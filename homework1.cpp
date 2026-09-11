#include <iostream>
#include <string>
using namespace std;

struct Flower {
    string name;
    double price;
    int qty;
    string type;
};

int main() {
    Flower arr[20]; 
    int n;

    // Nhập số lượng hoa
    cout << "How many flowers? "; cin >> n;
    if (n > 20) n = 20;

   // Nhập thông tin và kiểm tra điều kiện (Validate)
    for (int i = 0; i < n; i++) {
        cout << "Flower " << (i + 1) << ":\n";
        cout << "  Name: "; cin >> arr[i].name;
        
        do { cout << "  Price (>0): "; cin >> arr[i].price; } while (arr[i].price <= 0);
        do { cout << "  Quantity (>=0): "; cin >> arr[i].qty; } while (arr[i].qty < 0);
        
        cout << "  Type: "; cin >> arr[i].type;
    }

    // Hiển thị danh sách 
    cout << "\n===== FLOWER SHOP =====\nNo\tName\tPrice\tQty\tType\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "\t" << arr[i].name << "\t" << arr[i].price << "\t" << arr[i].qty << "\t" << arr[i].type << "\n";
    }

    int max_idx = 0, min_idx = 0, total_qty = 0;
    double sum_price = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i].price > arr[max_idx].price) max_idx = i;
        if (arr[i].price < arr[min_idx].price) min_idx = i;
        total_qty += arr[i].qty;
        sum_price += arr[i].price;
    }

    cout << "\n---- ANALYSIS ----\n";
    cout << "Most expensive flower : " << arr[max_idx].name << " (" << arr[max_idx].price << ")\n";
    cout << "Cheapest flower       : " << arr[min_idx].name << " (" << arr[min_idx].price << ")\n";
    cout << "Total quantity        : " << total_qty << "\n";
    cout << "Average price         : " << (n > 0 ? sum_price / n : 0) << "\n";

    // Đếm số lượng hoa theo từng loại 
    cout << "\n---- COUNT BY TYPE ----\n";
    for (int i = 0; i < n; i++) {
        bool is_duplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i].type == arr[j].type) { is_duplicate = true; break; }
        }
        if (!is_duplicate) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j].type == arr[i].type) count++;
            }
            cout << arr[i].type << " : " << count << "\n";
        }
    }

    // Tìm kiếm theo tên
    string search_name;
    cout << "\nEnter flower name to search: "; cin >> search_name;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].name == search_name) {
            cout << "Found!\nPrice: " << arr[i].price << "\nQuantity: " << arr[i].qty << "\nType: " << arr[i].type << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Not Found!\n";

    return 0;
}
