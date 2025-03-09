
class Student {
    protected String name;
    protected int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }
}
interface SportsInterface {
    int getSGrade();
}
interface ExamInterface {
    int getEGrade();
}
class Sports extends Student implements SportsInterface {
    protected int sGrade;

    public Sports(String name, int id, int sGrade) {
        super(name, id);
        this.sGrade = sGrade;
    }

    @Override
    public int getSGrade() {
        return sGrade;
    }
}
class Exam extends Student implements ExamInterface {
    protected int eGrade;

    public Exam(String name, int id, int eGrade) {
        super(name, id);
        this.eGrade = eGrade;
    }

    @Override
    public int getEGrade() {
        return eGrade;
    }
}

// Class Results implementing both interfaces
class Results implements SportsInterface, ExamInterface {
    private Sports sports;
    private Exam exam;
    private String finalResult;

    public Results(String name, int id, int sGrade, int eGrade) {
        this.sports = new Sports(name, id, sGrade);
        this.exam = new Exam(name, id, eGrade);
        calculateFinalResult();
    }

    private void calculateFinalResult() {
        if (sports.getSGrade() >= 50 && exam.getEGrade() >= 50) {
            finalResult = "Pass";
        } else {
            finalResult = "Fail";
        }
    }

    @Override
    public int getSGrade() {
        return sports.getSGrade();
    }

    @Override
    public int getEGrade() {
        return exam.getEGrade();
    }

    public void display() {
        System.out.println("Name: " + sports.getName());
        System.out.println("ID: " + sports.getId());
        System.out.println("Sports Grade: " + getSGrade());
        System.out.println("Exam Grade: " + getEGrade());
        System.out.println("Final Result: " + finalResult);
    }
}
public class  lab6q6 {
    public static void main(String[] args) {
        Results studentResult = new Results("John Doe", 12345, 75, 60);
        studentResult.display();
    }
}

