class StackMe{
    int[] arr;
    int idx;
    int max;

    StackMe(int max) {
        this.max = max;
        arr = new int[max];
        idx = -1;
    }

    void push(int val) {
        idx++;
        if (idx == max) {
            System.out.println("Overflow");
            return;
        }
        arr[idx] = val;
    }

    int pop() {
        if (idx == -1) {
            System.out.println("Underflowed");
            return -1;
        }
        int val = arr[idx];
        idx--;
        return val;
    }

    void print() {
        if(idx == -1){
            System.out.println("No values are there");
            return;
        }
        for(int i = idx; i >= 0;i--){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }


    public static void main(String[] args) {
        StackMe st = new StackMe(30);
        st.push(3);
        st.push(5);
        st.push(45);
        st.push(233);
        st.print();
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
    }
}

