# 🎬 Movie Seat Booking System in C (Linked List-Based)

A terminal-based Movie Seat Booking System implemented using a **Singly Linked List** in C. This system manages seat allocations across four categories (Premium, Gold, Silver, and General) with tax-inclusive pricing, cancellation, and dynamic reallocation of canceled seats.

---

## 🔧 Features

- ✅ Book seats in **Premium**, **Gold**, **Silver**, or **General** class
- ✅ Seat count limits:
  - Premium: 10
  - Gold: 15
  - Silver: 15
  - General: 20
- 💰 Automatically calculates price including tax:
  - 18% tax for tickets above ₹100
  - 12% tax otherwise
- 🔄 Canceled seats become **immediately available** for rebooking (first available seat reused)
- 🔍 Search by user name to view booking details
- ❌ Cancel bookings by class and seat number
- 📋 Display all booked seat details per class

---

## 🧠 Data Structures Used

- **Singly Linked List**: Used to dynamically manage seat allocations
- **Arrays**: Used to store booked names per class for display

Each node (`struct movie_seat`) represents a booking and contains:
- Name
- Class type
- Seat number
- Final price
- Link to the next seat

---

## 🗂️ Files Included

| File Name                  | Description                               |
|---------------------------|-------------------------------------------|
| `movie_seat_booking.c`    | Full C source code                        |
| `movie_seat_booking.exe`  | Compiled Windows executable               |
| `README.md`               | This documentation file                   |

---

## 🚀 How to Run

### Option 1: Run Precompiled `.exe` (Windows)
1. Double-click `movie_seat_booking.exe`
2. Follow the terminal prompts

### Option 2: Compile from Source
Using GCC:
```bash
gcc movie_seat_booking.c -o movie_seat_booking
./movie_seat_booking
