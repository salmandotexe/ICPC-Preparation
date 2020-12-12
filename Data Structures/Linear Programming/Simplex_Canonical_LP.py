import copy
from fractions import Fraction

c_b = {}
class SimplexSolver():
    def __init__(self):
        self.A = []
        self.b = []
        self.c = []
        self.tableau = []
        self.entering = []
        self.departing = []
        self.ineq = []
        self.prob = "max"

    def run_simplex(self, A, b, c, prob='max', ineq=[]):
        self.prob = prob
        self.ineq = ineq
        self.set_simplex_input(A, b, c)

        while not self.should_terminate():

            self._print_tableau()
            print('\n')

            pivot = self.find_pivot()
            if pivot[1] < 0:
                print("There exists no non-negative pivot. Thus, the solution is infeasible.")
                exit(0)
            else:
                self._print_tableau()
                print("\nNegative values exist in last row. solution can be optimized.");
                print("Entering variable: ",str(self.entering[pivot[0]]))
                print("Leaving variable: ", str(self.departing[pivot[1]]))
                print("Performing row operations to make pivot element 1 and other elements in column zero\n")
            self.pivot(pivot)

        solution = self.get_current_solution()

        self._print_tableau()
        return solution

    def set_simplex_input(self, A, b, c):
        for a in A:
            self.A.append([Fraction(x) for x in a])
        self.b = [Fraction(x) for x in b]
        self.c = [Fraction(x) for x in c]
        if not self.ineq:
            if self.prob == 'max':
                self.ineq = ['<='] * len(b)
            elif self.prob == 'min':
                self.ineq = ['>='] * len(b)

        self.update_enter_depart(self.get_Ab())

        if self.prob == 'min':
            m = self.get_Ab()
            m.append(self.c + [0])
            m = [list(t) for t in zip(*m)]
            self.A = [x[:(len(x) - 1)] for x in m]
            self.b = [y[len(y) - 1] for y in m]
            self.c = m[len(m) - 1]
            self.A.pop()
            self.b.pop()
            self.c.pop()
            self.ineq = ['<='] * len(self.b)

        self.create_tableau()
        self.ineq = ['='] * len(self.b)
        self.update_enter_depart(self.tableau)

    def update_enter_depart(self, matrix):
        self.entering = []
        self.departing = []
        for i in range(0, len(matrix[0])):
            if i < len(self.A[0]):
                prefix = 'x' if self.prob == 'max' else 'y'
                self.entering.append("%s_%s" % (prefix, str(i + 1)))
            elif i < len(matrix[0]) - 1:
                self.entering.append("s_%s" % str(i + 1 - len(self.A[0])))
                self.departing.append("s_%s" % str(i + 1 - len(self.A[0])))
            else:
                self.entering.append("b")

    def add_slack_variables(self):
        slack_vars = self._generate_identity(len(self.tableau))
        for i in range(0, len(slack_vars)):
            self.tableau[i] += slack_vars[i]
            self.tableau[i] += [self.b[i]]

    def create_tableau(self):
        self.tableau = copy.deepcopy(self.A)
        self.add_slack_variables()
        c = copy.deepcopy(self.c)
        for index, value in enumerate(c):
            c[index] = -value
        self.tableau.append(c + [0] * (len(self.b) + 1))

    def find_pivot(self):
        enter_index = self.get_entering_var()
        depart_index = self.get_departing_var(enter_index)
        return [enter_index, depart_index]

    def pivot(self, pivot_index):
        j, i = pivot_index
        pivot = self.tableau[i][j]
        self.tableau[i] = [element / pivot for element in self.tableau[i]]
        for index, row in enumerate(self.tableau):
            if index != i:
                row_scale = [y * self.tableau[index][j] for y in self.tableau[i]]
                self.tableau[index] = [x - y for x, y in zip(self.tableau[index], row_scale)]
        self.departing[i] = self.entering[j]

    def get_entering_var(self):
        bottom_row = self.tableau[len(self.tableau) - 1]
        most_neg_ind = 0
        most_neg = bottom_row[most_neg_ind]
        for index, value in enumerate(bottom_row):
            if value < most_neg:
                most_neg = value
                most_neg_ind = index
        return most_neg_ind

    def get_departing_var(self, entering_index):
        skip = 0
        min_ratio_index = -1
        min_ratio = 0
        for index, x in enumerate(self.tableau):
            if x[entering_index] != 0 and x[len(x) - 1] / x[entering_index] > 0:
                skip = index
                min_ratio_index = index
                min_ratio = x[len(x) - 1] / x[entering_index]
                break
        if min_ratio > 0:
            for index, x in enumerate(self.tableau):
                if index > skip and x[entering_index] > 0:
                    ratio = x[len(x) - 1] / x[entering_index]
                    if min_ratio > ratio:
                        min_ratio = ratio
                        min_ratio_index = index
        return min_ratio_index

    def get_Ab(self):
        matrix = copy.deepcopy(self.A)
        for i in range(0, len(matrix)):
            matrix[i] += [self.b[i]]
        return matrix

    def should_terminate(self):
        result = True
        index = len(self.tableau) - 1
        for i, x in enumerate(self.tableau[index]):
            if x < 0 and i != len(self.tableau[index]) - 1:
                result = False
        return result

    def get_current_solution(self):
        solution = {}
        for x in self.entering:
            if x != 'b':
                if x in self.departing:
                    solution[x] = self.tableau[self.departing.index(x)] \
                        [len(self.tableau[self.departing.index(x)]) - 1]
                else:
                    solution[x] = 0
        solution['z'] = self.tableau[len(self.tableau) - 1] \
            [len(self.tableau[0]) - 1]

        if (self.prob == 'min'):
            bottom_row = self.tableau[len(self.tableau) - 1]
            for v in self.entering:
                if 's' in v:
                    solution[v.replace('s', 'x')] = bottom_row[self.entering.index(v)]

        return solution

    def _generate_identity(self, n):
        I = []
        for i in range(0, n):
            row = []
            for j in range(0, n):
                if i == j:
                    row.append(1)
                else:
                    row.append(0)
            I.append(row)
        return I

    def _print_matrix(self, M):
        for row in M:
            print("| ",end="")
            for val in row:
                print('{:^5}'.format(str(val)), end=" ")
            print(" |")

    def _print_tableau(self):
        print("", end=" ")

        for val in self.entering:
            if val!='b':
                print('{:^5}'.format(c_b[str(val)]), end=" ")
        print("")

        for val in self.entering:
            print('{:^5}'.format(str(val)), end=" ")
        print('{:^9}'.format(str("Basis")), end=" ")
        print('{:^5}'.format(str("c_b")), end=" ")
        print("")

        it = 0
        for num, row in enumerate(self.tableau):
            print("|", end="")
            for index, val in enumerate(row):
                print('{:^5}'.format(str(val)), end=" ")
            if num < (len(self.tableau) - 1):
                print(" |", end=" ");
                print(str(self.departing[num]), end="");
                print(" |", end=" ");
                print('{:^7}'.format(c_b[str(self.departing[num])]), end=" ")
                print("")
            else:
                print(" |", end=" ");
                print(" RP", end="")
                print(" |", end=" ");
                print("")
        print("")

if __name__ == '__main__':

    # Provide Ax<=b form if p='max'
    
    '''
               3x1 +  x2 <= 180
                x1 + 2x2 <= 100
              -2x1 + 2x2 <= 40

              x_i >=0 for all i.
              b_i >=0 for all b.
    
    '''
    
    A = [[3, 1], [1, 2], [-2, 2]]
    b = [180, 100, 40]
    c = [4, 12]
    p = 'max'

    # Provide Ax>=b form if p='min'
    
    for id, val in enumerate(c):
        c_b["x_"+str(id+1)] = val;
    for id,val in enumerate(A):
        c_b["s_" + str(id + 1)] = 0;

    LPSolver = SimplexSolver()
    result = LPSolver.run_simplex(A, b, c, prob=p)

    print("Solutuion found: ");
    for i, var in enumerate(result):
        print(var, " = ", result[var]);

