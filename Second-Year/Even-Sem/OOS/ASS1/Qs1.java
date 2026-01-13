class Room{
    int height;
    int width;
    int breadth;
    Room(int h, int w, int b){
        height = h;
        width = w;
        breadth = b;
    }
    int volume(){
        return height * width * breadth;
    }
}

class RoomDemo{
    public static void main(String[] args) {
        Room r = new Room(2, 3, 4);
        System.out.println("The volume of the room is: " + r.volume());
    }
}