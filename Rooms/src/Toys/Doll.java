package Toys;

/**
 * Игрушка - кукла
 */
public class Doll extends Toy{

    private String gender; //пол куклы (женский, мужской)

    public Doll(double cost, String gender) {
        super(cost);
        this.gender = gender;
    }

    public Doll() {

    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    @Override
    public String toString() {
        return "Doll: " +
                "cost " + cost +
                ", gender " + gender;
    }
}
