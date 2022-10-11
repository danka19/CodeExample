package Toys;

/**
 * Игрушка - мяч
 */
public class Ball extends Toy{

    private String type; // баскетбольный, волейбольный и т.д.

    public Ball(double cost, String type) {
        super(cost);
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return "Ball: " +
                "cost " + cost +
                ", type " + type;
    }
}
