# Medical Billing System in C

This is a terminal-based **Medical Billing System** written in C that allows pharmacies or clinics to manage customers, medicines, billing, and loyalty points.

## 💡 Features

- Add new customer with auto-generated customer ID
- Store and check loyalty points for customers
- Generate itemized bills for medicine purchases
- Apply loyalty points as discounts during billing
- CSV file-based data persistence

## 🗂️ File Structure

- `medical_billing.c`: Main source code containing all the functionality.
- `customer_info.csv`: Stores customer data (ID, Name, Age, Number, Points).
- `medicine.csv`: Stores medicine details (ID, Name, Type, Cost). Must be prefilled.

## 🛠️ How to Run

1. Compile the code using a C compiler (like GCC):
   ```bash
   gcc medical_billing.c -o medical_billing.exe
   ```

2. Run the program:
   ```bash
   ./medical_billing.exe
   ```

3. Interact using the menu:
   - Add customer
   - Check loyalty points
   - Process billing

## 📁 CSV Format

### customer_info.csv
```
Customer ID,Customer Name,Customer Age,Customer Number,Loyalty Points
1,Alice,25,="9876543210",5.0
```

### medicine.csv
```
MedID,MedName,Type,Cost
M101,Paracetamol,Tablet,12.5
```

> Note: The phone number uses Excel-friendly `="..."` format but is normalized internally.

## ⚠️ Dependencies
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, etc.)

## 📌 Author
Piyush A Patel

## 📝 License
MIT License - see `LICENSE` file.
