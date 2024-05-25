#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void taoHoaDon(vector<string> monDat, vector<float> giaTien, float& tongTien) {
    time_t now = time(0);
    tm *t = localtime(&now);
    string tenFile = "hoa_don_ngay_" + to_string(t->tm_mday) + "_" + to_string(t->tm_mon + 1) + "_" + to_string(t->tm_year + 1900) + ".txt";
    ofstream f(tenFile);
    if (f.is_open()) {
    f << "---- Hoa don " << t->tm_mday << "/" << t->tm_mon + 1 << "/" << t->tm_year + 1900 << " ----\n";
    for (int i = 0; i < monDat.size(); ++i) {
        f << monDat[i] << " - " << giaTien[i] << " VND" << endl;
    }
    f << "Tong tien: " << tongTien << " VND" << endl;
    f.close();
    cout << "Luu hoa don thanh cong!" << endl;
  } else {
    cout << "Loi mo file!" << endl;
  }
}
