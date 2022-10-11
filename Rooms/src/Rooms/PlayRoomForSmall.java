package Rooms;

/**
 * Игровая комната для маленьких детей
 */
public class PlayRoomForSmall extends PlayRoom {
    public PlayRoomForSmall(double deposit) {
        super(deposit);
    }

    @Override
    public String toString() {
        return "PlayRoomForSmall: " +
                "deposit=" + deposit +
                ", money=" + getMoney()+
                " ,description " + description;
    }
}
