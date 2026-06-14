# 🏦 Hệ Thống Quản Lý Tài Khoản Ngân Hàng (Bank Management System)

[![C++](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Completed-success.svg)]()

Đồ án cuối kỳ môn **Kỹ thuật lập trình**. 
Đây là một ứng dụng Console mô phỏng hệ thống Core Banking cơ bản, cho phép quản lý khách hàng, tài khoản và thực hiện các giao dịch tài chính cốt lõi. 

Điểm đặc biệt của dự án này là **tuân thủ nghiêm ngặt các giới hạn về mặt kỹ thuật**: Xây dựng hoàn toàn bằng C++ cơ bản, tự cài đặt cấu trúc dữ liệu và thuật toán xử lý mà không phụ thuộc vào các thư viện cấu trúc nâng cao có sẵn (như `std::vector`, `std::list`).

---

## 🚀 Các Tính Năng Cốt Lõi (Features)

* **Quản lý Tài khoản:**
    * Đăng ký tài khoản mới (Cấp số dư mặc định 50,000 VNĐ).
    * Đăng nhập hệ thống & Xác thực bằng mã PIN bảo mật.
* **Giao dịch Tài chính:**
    * **Nạp tiền:** Cộng tiền trực tiếp vào tài khoản.
    * **Rút tiền:** Rút tiền mặt với điều kiện kiểm tra số dư tối thiểu (duy trì 50,000 VNĐ).
    * **Chuyển khoản:** Chuyển tiền nội bộ giữa các tài khoản, thực hiện giao dịch nguyên tử (Atomic) đảm bảo tính toàn vẹn dữ liệu.
* **Truy vấn & Báo cáo:**
    * Lưu trữ tự động mọi biến động số dư.
    * In sao kê (Statement) chi tiết lịch sử giao dịch của một tài khoản bất kỳ.
* **Lưu trữ Dữ liệu (File I/O):**
    * Dữ liệu được đọc/ghi trực tiếp xuống các tệp `.txt` để đảm bảo không bị mất sau khi đóng chương trình.

---

## 🛠 Kỹ Thuật Áp Dụng (Technical Details)

Dự án được xây dựng với mục tiêu rèn luyện tư duy lập trình và quản lý bộ nhớ:

* **Ngôn ngữ:** C++ (Standard)
* **Cấu trúc dữ liệu:** Sử dụng `struct` kết hợp với Mảng tĩnh (Static Arrays) để quản lý danh sách thực thể. Không sử dụng thư viện STL nâng cao.
* **Thuật toán:** Tự cài đặt thuật toán Tìm kiếm tuyến tính (Linear Search) để truy vấn tài khoản và lịch sử giao dịch.
* **Kiến trúc mã nguồn:** Mã nguồn được module hóa thông qua các hàm bổ trợ (Helper functions) giúp giảm thiểu sự lặp lại mã (DRY - Don't Repeat Yourself).

---
