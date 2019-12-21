std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
start = std::chrono::high_resolution_clock::now();
/*
Code goes here
*/
end = std::chrono::high_resolution_clock::now();
ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
cout << "\nElapsed Time: " << elapsed_time << "ms\n";
