class BankAccount {
    static int accNo = 100000;
    float bal;
    String ownerName;

    BankAccount(String name, float bal) {
        ownerName = name;
        this.bal = bal;
        System.out.println("Your acc No is : " + accNo++);
    }

    void balance() {
        System.out.println(ownerName + " has " + bal + " in bank.");

    }

    void add(float cash) {
        this.bal += cash;
        System.out.println("Deposited succesfully.");

    }

    float withdraw(float amnt) {
        if (amnt > this.bal) {
            System.out.println("You dont have this enough amount.");
            return -1f;
        }
        this.bal -= amnt;
        System.out.println("withdrawn sucessfully.");
        return this.bal;

    }

    // public static void main(String[] args) {
    // BankAccount acc1 = new BankAccount("Rakesh", 10000);
    // System.out.println(acc1.withdraw(23));
    // BankAccount acc2 = new BankAccount("Prerana", 1232);
    // }
}

class AccountManager {
    BankAccount[] arr;
    int idx = 0;
    int max;

    AccountManager(int n) {
        this.max = n;
        arr = new BankAccount[n];
        System.out.println(n + " register for no of bank is created.");
    }

    void createBank(String name, float bal) {
        if (max > idx) {
            arr[idx] = new BankAccount(name, bal);
            this.idx++;

        } else {
            System.out.println("Register full no bank acc possible.");
        }

    }

    BankAccount deleAccount(int accNo) {
        if (idx == max) {
            for (int i = idx - 1; i >= 0; i--) {
                if (accNo == arr[i].accNo) {
                    return arr[i];
                }
            }
        } else if (idx < max) {
            for (int i = idx; i >= 0; i--) {
                if(accNo == arr[i].accNo){
                    return arr[i];
                }
            }
        }
        System.out.println("Invalid accNo");
        return null;
    }

    void depositAtAcc(int accNo, float value){
        // BankAccount ba;
        if (idx == max) {
            for (int i = idx - 1; i >= 0; i--) {
                if (accNo == arr[i].accNo) {
                    arr[i].bal += value;
                    return;
                }
            }
        } else if (idx < max) {
            for (int i = idx; i >= 0; i--) {
                if(accNo == arr[i].accNo){
                    arr[i].bal += value;
                    return;
                }
            }
        }
        System.out.println("Invalid accNo");
    }

    float withdrawFromAcc(int accNo, float value){
        if (idx == max) {
            for (int i = idx - 1; i >= 0; i--) {
                if (accNo == arr[i].accNo) {
                    arr[i].bal -= value;
                    return arr[i].bal;
                }
            }
        } else if (idx < max) {
            for (int i = idx; i >= 0; i--) {
                if(accNo == arr[i].accNo){
                    arr[i].bal -= value;
                    return arr[i].bal;
                }
            }
        }
        System.out.println("Invalid accNo");
        return -1f;
    }



}


class Bank{
    public static void main(String[] args) {
        AccountManager accs = new AccountManager(10);
        accs.createBank("Rakesh", 1000);
        

    }
}