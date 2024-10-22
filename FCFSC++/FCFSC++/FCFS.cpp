#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Process {
    int arrivalTime;  // Thời gian đến
    int burstTime;    // Thời gian bùng nổ
    int processID;    // ID quy trình
};

// Hàm so sánh để sắp xếp quy trình theo thời gian đến
bool compare(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

int main() {
    int n;

    // Nhập số lượng quy trình
    cout << "Nhap so luong quy trinh: ";
    cin >> n;

    vector<Process> processes(n);

    // Nhập thời gian đến và thời gian bùng nổ cho từng quy trình
    for (int i = 0; i < n; ++i) {
        cout << "nhập thoi gian den va thoi gian bung no cho quy trinh " << i + 1 << ": ";
        processes[i].processID = i + 1; // Lưu ID quy trình
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    // Sắp xếp quy trình theo thời gian đến
    sort(processes.begin(), processes.end(), compare);

    vector<int> completionTime(n);
    vector<int> waitingTime(n);
    int totalWaitingTime = 0;

    // Tính toán thời gian hoàn thành và thời gian chờ
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            completionTime[i] = processes[i].arrivalTime + processes[i].burstTime;
        }
        else {
            completionTime[i] = max(completionTime[i - 1], processes[i].arrivalTime) + processes[i].burstTime;
        }

        waitingTime[i] = completionTime[i] - processes[i].arrivalTime - processes[i].burstTime;
        totalWaitingTime += waitingTime[i];
    }

    // Tính thời gian trung bình
    double averageWaitingTime = static_cast<double>(totalWaitingTime) / n;

    // In bảng thông số
    cout << setw(15) << "QT"
         << setw(15) << "TGD"
         << setw(15) << "TGBN"
         << setw(15) << "TGHT"
         << setw(15) << "TGC" << std::endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(15) << processes[i].processID
             << setw(15) << processes[i].arrivalTime
             << setw(15) << processes[i].burstTime
             << setw(15) << completionTime[i]
             << setw(15) << waitingTime[i] << endl;
    }

    std::cout << "Thoi gian cho trung binh la: " << averageWaitingTime << " don vi thoi gian\n";

    return 0;
}

