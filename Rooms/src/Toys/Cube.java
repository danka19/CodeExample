package Toys;

/**
 * Игрушка - куб
 */
public class Cube extends Toy{

    private String color;

    public Cube(double cost, String color) {
        super(cost);
        this.color = color;
    }


    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Cube: " +
                "cost " + cost +
                ", color " + color;
    }
}
