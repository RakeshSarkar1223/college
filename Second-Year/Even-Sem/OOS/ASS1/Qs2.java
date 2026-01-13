class Student{
    static int no_of_student;
    String name;
    int mark1, mark2, mark3;

    public Student(String n) {
        this.name = n;
        no_of_student++;
    }
    
    void asign(int m1, int m2, int m3){
        this.mark1 = m1;
        this.mark2 = m2;
        this.mark3 = m3;
    }
    double avg(){
        return ((mark1 + mark2 + mark3)/ 3.0);
    }

    void display(){
        System.out.println("Name : " + this.name + " and Total marks obtained : " + (mark1 + mark2 + mark3));
    }
}

class Qs2{
    public static void main(String[] args) {
        Student s1 = new Student("Rakesh");
        s1.asign(90, 100, 100);
        Student s2 = new Student("Prerana");
        s2.display();
        s1.display();
        System.out.println(s1.avg());
        System.out.println(Student.no_of_student);
    }
}