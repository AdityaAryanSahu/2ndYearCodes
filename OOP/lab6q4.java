 class building {
    int sqfoot;
    int stories;
    void setSqfoot(int foot){
        this.sqfoot=foot;
    }
    int getSqfoot(){
        return sqfoot;
    }
     void setStories(int stories){
         this.stories=stories;
     }
     int getStories(){
         return stories;
     }
}
class house extends building{
    int bedrooms;
    int bath;
    void setBedrooms(int bedrooms){
        this.bedrooms=bedrooms;
    }
    int getBedrooms(){
        return bedrooms;
    }
    void setBath(int bath){
        this.bath=bath;
    }
    int getBath(){
        return bath;
    }
}
class school extends building{
    int classrooms;
    String garde;
    void setClassrooms(int classrooms){
        this.classrooms=classrooms;
    }
    int getClassrooms(){
        return classrooms;
    }
    void setGarde(String garde){
        this.garde=garde;
    }
    String getGarde(){
        return garde;
    }
}
public class lab6q4{
    public static void main(String[] args) {
        System.out.println("for class building");
        int stories,classrooms,sqfoot,bath,bedrooms;
        String garde;
        building ob1=new building();
        ob1.setSqfoot(200);
        System.out.println("sqfoot is:");
        sqfoot=ob1.getSqfoot();
        System.out.println(sqfoot);
        ob1.setStories(10);
        System.out.println("stories is:");
        stories=ob1.getStories();
        System.out.println(stories);


        System.out.println("\nfor claass school");
        school ob2=new school();
        ob2.setSqfoot(1300);
        System.out.println("sqfoot is:");
       sqfoot= ob2.getSqfoot();
        System.out.println(sqfoot);
        ob2.setClassrooms(30);
        System.out.println("no of classrooms is");
        classrooms=ob2.getClassrooms();
        System.out.println(classrooms);
        ob2.setGarde("elementary");
        System.out.println("grade is");
        garde=ob2.getGarde();
        System.out.println(garde);
        ob2.setStories(2);
        System.out.println("stories is:");
        stories=ob2.getStories();
        System.out.println(stories);


        System.out.println("\nfor claass house");
        house ob3=new house();
        ob3.setSqfoot(400);
        System.out.println("sqfoot is:");
        sqfoot= ob3.getSqfoot();
        System.out.println(sqfoot);
        ob3.setBath(4);
        System.out.println("no of baths is");
        classrooms=ob3.getBath();
        System.out.println(classrooms);
        ob3.setBedrooms(5);
        System.out.println("no of bedrooms is");
        bedrooms=ob3.getBedrooms();
        System.out.println(bedrooms);
        ob3.setStories(4);
        System.out.println("stories is:");
        stories=ob3.getStories();
        System.out.println(stories);
    }
}
