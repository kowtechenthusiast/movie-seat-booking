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
> 📁 **To Run the Project Executable:**
> 
> 1. Download and extract `movie_seat_booking.zip` from the repository.
> 2. Inside, you'll find `movie_seat_booking.exe`.
> 3. Double-click the `.exe` file to launch it in the terminal (Windows only).
> 
> ⚠️ **Note:** Microsoft Defender SmartScreen may warn you that the file is from an unknown publisher.  
> This is a standard warning for executables not downloaded from the Microsoft Store or verified publishers.
> 
> 👉 You can safely run this file by clicking:
> 
> - **"More info" → "Run anyway"**
> 
> This executable is compiled from open-source C code available in this repository and is safe to use.


### Option 2: Compile from Source
Using GCC:
```bash
gcc movie_seat_booking.c -o movie_seat_booking
./movie_seat_booking
