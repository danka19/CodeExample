package Rooms;

/**
 * Игровая комната для детей средрего возраста
 */
public class PlayRoomForMedium extends PlayRoom{
    public PlayRoomForMedium(double deposit) {
        super(deposit);
    }

    @Override
    public String toString() {
        return "PlayRoomForMedium: " +
                "deposit=" + deposit +
                ", money=" + getMoney()+
                " ,description " + description;
    }
}
