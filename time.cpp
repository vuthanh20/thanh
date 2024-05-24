#include <iostream>
#include <ctime>
#include <time.h>

class Time {
private:
  std::time_t timeValue; // Biến lưu trữ giá trị thời gian (timestamp)

public:
  Time(); // Hàm tạo mặc định
  void getRealTime(); // Hàm lấy thời gian thực
  void printTime(); // Hàm in thời gian

  // Các hàm khác (nếu cần)
};
// Hàm tạo mặc định
Time::Time() {
  getRealTime(); // Gọi hàm lấy thời gian thực khi khởi tạo đối tượng
}

// Hàm lấy thời gian thực
void Time::getRealTime() {
  timeValue = std::time(nullptr); // Lấy timestamp hiện tại
}

// Hàm in thời gian
void Time::printTime() {
  std::tm* timeInfo = std::localtime(&timeValue); // Chuyển timestamp sang struct tm
  if (timeInfo != nullptr) {
    std::cout << std::asctime(timeInfo); // In thời gian theo định dạng asctime
  } else {
    std::cout << "Error getting local time" << std::endl;
  }
}
int main() {
  // Tạo đối tượng Time
  Time currentTime;

  // Nhập chuỗi ký tự
  std::string userInput;
  std::cout << "Nhập chuỗi ký tự: ";
  std::getline(std::cin, userInput);

  // In chuỗi ký tự và thời gian thực
  std::cout << "Chuỗi ký tự: " << userInput << std::endl;
  currentTime.printTime();

  return 0;
}

