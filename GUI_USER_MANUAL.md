# GUI Usage Guide - Bank System v2.0

## Quick Start

### Starting the Application
```bash
cd /home/ragab/vscode_workspace/bank_system/build/app
./bank_system
```

## Tab Navigation

### 1. Create Account Tab
**Purpose:** Create new bank accounts with person information

**Steps:**
1. Enter **Person Name** (e.g., "Ahmed Hassan")
2. Enter **National Card ID** (14 digits, e.g., "12345678901234")
3. Enter **Initial Balance** (optional, e.g., "5000")
4. Click **Create Account** button

**Validation:**
- Person name cannot be empty
- Card ID must be at least 14 digits
- Initial balance must be positive

**Success Indicator:**
- Green status message: "✓ Account created successfully!"

---

### 2. Account Details Tab (NEW)
**Purpose:** View complete information for a specific account

**Steps:**
1. Enter the **Account ID** (same as the card ID used at creation)
2. Click **View Details** button
3. Information displayed includes:
   - Account ID
   - Owner Name (Person who created it)
   - Current Balance
   - Account Creation Time
   - Last Operation (Type and Time)

**Example:**
- Account ID: `12345678901234`
- Shows: "Owner: Ahmed Hassan, Balance: $5,000.00, Last Op: Deposit - 2024-01-15 14:30:22"

---

### 3. Manage Account Tab
**Purpose:** Perform transactions on existing accounts

**Steps:**

**To Load Balance:**
1. Enter **Account ID**
2. Click **Load Balance** button
3. Balance displays in blue box

**To Deposit:**
1. Enter **Account ID**
2. Enter **Amount** (must be positive)
3. Click **Deposit** button
4. Balance updates automatically
5. Status shows new balance

**To Withdraw:**
1. Enter **Account ID**
2. Enter **Amount** (must be positive AND less than balance)
3. Click **Withdraw** button
4. If insufficient funds: "❌ Error: Insufficient balance"
5. If successful: Balance updates

**To Delete Account:**
1. Enter **Account ID**
2. Click **Delete** button
3. Account is permanently removed
4. All data for that account is lost

**Error Messages:**
- "❌ Account not found" - Invalid account ID
- "❌ Insufficient balance" - Withdrawal amount exceeds balance
- "❌ Please enter valid account ID and amount" - Missing or invalid inputs

---

### 4. Search Person Tab (NEW)
**Purpose:** Find all accounts belonging to a specific person

**Steps:**
1. Enter **Person Name** (e.g., "Ahmed Hassan")
2. Click **Search** button
3. Results display in text area showing:
   - Account ID
   - Owner Name
   - Balance for each matching account

**Example Output:**
```
Account ID: 12345678901234
  Owner: Ahmed Hassan
  Balance: $ 5,000.00

Account ID: 98765432109876
  Owner: Ahmed Hassan
  Balance: $ 2,500.50
```

**Notes:**
- Search is case-sensitive
- Returns all accounts for that person
- If no accounts found: "No accounts found for person: [name]"

---

### 5. All Accounts Tab (NEW)
**Purpose:** View details of every account in the system

**Steps:**
1. Click **Refresh All Accounts** button
2. System loads all accounts
3. Each account displays:
   - Account ID
   - Owner Name
   - Current Balance
   - Creation Date/Time
   - Last Operation (Type and Time)

**Example Output:**
```
========================
Account ID: 12345678901234
Owner: Ahmed Hassan
Balance: $ 5,000.00
Created: 2024-01-15 10:30:45
Last Operation: Deposit (2024-01-15 14:30:22)

========================
Account ID: 11111111111111
Owner: Sara Mohamed
Balance: $ 3,200.75
Created: 2024-01-14 09:15:30
Last Operation: Withdrawal (2024-01-15 13:45:10)
```

**Tips:**
- Use scroll bar to view if many accounts
- Refresh to get latest data after operations
- Shows real-time balances

---

## Status Messages

| Message | Meaning | Action |
|---------|---------|--------|
| ✓ Account created: [Name] | Success | Continue to other tabs |
| ✓ Balance updated to: $X | Success | Transaction completed |
| ✓ [Message] | Success | Operation completed |
| ❌ Error: [Details] | Failure | Check inputs and retry |
| ❌ Account not found | Failure | Verify Account ID is correct |
| ❌ Insufficient balance | Failure | Reduce withdrawal amount |
| ❌ Please enter... | Validation | Fill all required fields |

---

## Save and Exit

### Save Data
- Click **Save** button (blue button at bottom right)
- Data persists to `accounts.json`
- Status shows: "✓ Data saved successfully!"

### Exit Application
- Click **Exit** button (red button at bottom right)
- Application closes
- Data automatically saved on close

---

## Data Persistence

### Where Data is Stored
```
/home/ragab/vscode_workspace/bank_system/build/app/accounts.json
```

### Automatic Save
- Data saves automatically on each transaction
- Also saves when "Save" button clicked
- JSON format with full metadata

### Data Restored On Startup
- Previous accounts and balances loaded automatically
- Operation history (last op time/type) preserved
- All person information retained

---

## Common Use Cases

### Scenario 1: Create Account and Deposit
1. Go to **Create Account** tab
2. Enter name and card ID (14 digits)
3. Set initial balance (e.g., 1000)
4. Account created with $1,000
5. Go to **Manage Account** tab
6. Enter same account ID
7. Load balance to verify
8. Deposit additional $500
9. New balance: $1,500

### Scenario 2: Find Person's Accounts
1. Go to **Search Person** tab
2. Type person's name
3. Click Search
4. See all their accounts and balances
5. Choose one and go to **Account Details** to see full info

### Scenario 3: Monthly Statement Check
1. Go to **All Accounts** tab
2. Click **Refresh All Accounts**
3. Review all account balances
4. Check last operation times
5. Click **Save** to ensure data persisted

### Scenario 4: Close an Account
1. Go to **Manage Account** tab
2. Enter account ID to delete
3. Click **Delete** button
4. Account permanently removed
5. Verify in **All Accounts** that it's gone

---

## Troubleshooting

### Problem: "Account not found"
**Solution:** 
- Verify the Account ID is correct
- Check in **All Accounts** tab for exact ID
- Make sure account wasn't deleted

### Problem: Withdrawal rejected with "Insufficient balance"
**Solution:**
- Go to **Manage Account** and load balance
- Check current balance displayed
- Enter withdrawal amount less than balance

### Problem: Search Person returns no results
**Solution:**
- Check exact spelling of person's name
- Search is case-sensitive
- Create at least one account for that person
- Verify in **All Accounts** tab

### Problem: Data not saved
**Solution:**
- Click **Save** button explicitly
- Data auto-saves but use Save to be sure
- Check file permissions in build/app directory
- Verify no write errors in status message

### Problem: Application won't start
**Solution:**
- Rebuild: `cd build && cmake --build .`
- Check for error messages in terminal
- Verify Qt6 is installed: `apt-get install qt6-base-dev`

---

## Keyboard Shortcuts

- **Tab Key**: Move between input fields
- **Enter/Return**: Activate focused button
- **Ctrl+Q**: Exit application (if supported)

---

## Best Practices

1. **Always use 14-digit Card IDs:**
   - Format: NNNNNNNNNNNNNN (numbers only)
   - Example: 12345678901234

2. **Save Regularly:**
   - Click Save after important transactions
   - Data auto-saves but explicit save ensures persistence

3. **Verify Balances:**
   - Use "Load Balance" before transactions
   - Check "Account Details" for operation history

4. **Back Up Data:**
   - Copy `accounts.json` file periodically
   - Keep previous versions for recovery

5. **Person Names:**
   - Use consistent naming (e.g., "Ahmed Hassan" not "AHMED HASSAN")
   - Use full names for better search results

---

## Technical Details for Developers

### Account ID System
- Uses Card ID as Account ID for unique identification
- 14-digit format ensures uniqueness
- Stored in JSON database

### Balance Precision
- Stored and displayed to 2 decimal places
- Calculations use double precision
- No currency symbol in storage (display adds $)

### Operation Tracking
- System automatically records:
  - Type of operation (Deposit/Withdrawal)
  - Exact timestamp (YYYY-MM-DD HH:MM:SS format)
  - Updated balance after operation

### Metadata Stored Per Account
- Person Name
- National Card ID
- Creation Time
- Current Balance
- Last Operation Type
- Last Operation Time

---

**Application Version:** 2.0
**Build Status:** Production Ready
**Last Updated:** January 2024
