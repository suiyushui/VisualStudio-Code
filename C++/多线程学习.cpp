// #include <iostream>
// #include <vector>
// #include <thread>
// #include <mutex>
// #include <cstdlib>  // for rand()
// #include <ctime>    // for time()
// #include <algorithm>
// #include <numeric>

// // 全局位图和互斥锁
// std::vector<bool> globalBitmap(100001, false);
// std::mutex mtx;

// // 线程处理函数
// void processChunk(const std::vector<int>& chunk, std::vector<int>& uniqueQqNumbers) {
//     std::vector<bool> localBitmap(100001, false);
    
//     for (int qq : chunk) {
//         if (!globalBitmap[qq] && !localBitmap[qq]) {
//             std::lock_guard<std::mutex> lock(mtx);
//             if (!globalBitmap[qq]) {
//                 uniqueQqNumbers.push_back(qq);
//                 globalBitmap[qq] = true;
//             }
//             localBitmap[qq] = true;
//         }
//     }
// }

// std::vector<int> removeDuplicatesWithMultithreading(const std::vector<int>& qqNumbers, int numThreads) {
//     std::vector<std::thread> threads;
//     std::vector<std::vector<int>> chunks(numThreads);
//     std::vector<std::vector<int>> results(numThreads);
    
//     // 将QQ号码分成多个子集
//     int chunkSize = qqNumbers.size() / numThreads;
//     for (int i = 0; i < numThreads; ++i) {
//         int start = i * chunkSize;
//         int end = (i == numThreads - 1) ? qqNumbers.size() : (i + 1) * chunkSize;
//         chunks[i] = std::vector<int>(qqNumbers.begin() + start, qqNumbers.begin() + end);
//     }
    
//     // 启动多个线程来处理每个子集
//     for (int i = 0; i < numThreads; ++i) {
//         threads.emplace_back(processChunk, std::ref(chunks[i]), std::ref(results[i]));
//     }
    
//     // 等待所有线程完成
//     for (auto& t : threads) {
//         t.join();
//     }
    
//     // 合并所有线程的结果
//     std::vector<int> uniqueQqNumbers;
//     for (const auto& res : results) {
//         uniqueQqNumbers.insert(uniqueQqNumbers.end(), res.begin(), res.end());
//     }
    
//     // 可选：对结果进行排序（如果需要有序的结果）
//     std::sort(uniqueQqNumbers.begin(), uniqueQqNumbers.end());
    
//     return uniqueQqNumbers;
// }

// int main() {
//     // 设置随机数种子
//     std::srand(static_cast<unsigned int>(std::time(0)));
    
//     // 生成100000个随机QQ号码，范围在1到100000之间
//     std::vector<int> qqNumbers(100000);
//     std::generate(qqNumbers.begin(), qqNumbers.end(), []() { return std::rand() % 100000 + 1; });

//     // 使用多线程去重
//     int numThreads = 4;  // 假设使用4个线程
//     std::vector<int> uniqueQqNumbers = removeDuplicatesWithMultithreading(qqNumbers, numThreads);
    
//     std::cout << "去重后的QQ号码数量: " << uniqueQqNumbers.size() << std::endl;
    
//     // 输出去重后的QQ号码（可选，仅用于验证）
//     // for (int qq : uniqueQqNumbers) {
//     //     std::cout << qq << " ";
//     // }
//     // std::cout << std::endl;
    
//     return 0;
// }


