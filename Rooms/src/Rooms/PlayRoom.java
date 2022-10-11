package Rooms;

import Toys.*;
import stream_file.*;

import java.util.*;
import java.util.logging.Level;

/**
 * Фабричный паттерн игровой комнаты
 */

public abstract class PlayRoom{

    PlayRoom(double deposit){
        this.deposit = deposit;
    }

    protected double deposit; //на какую сумму можно закупать игрушки
    protected double money; //на какую сумму игрушки уже закуплены
    protected String description = "/нет описания/";

    private ArrayList<Toy> toys = new ArrayList<>(); //все игрушки хранятся тут

    /**
     * сеттеры и геттеры
     */
    public ArrayList<Toy> getToys() {
        return toys;
    }

    public void setDeposit(double deposit) {
        this.deposit = deposit;
    }

    public double getDeposit() {
        return deposit;
    }

    public void addToy(Toy toy){
        toys.add(toy);
    }

    public double getMoney() {
        return money;
    }

    public void addMoney(double cost){
        this.money += cost;
    }

    /**
     *  проверка хватает ли денег на добавляемую игрушку
     * @param cost на вход получает стоимость игрушки
     * @return возвращает булево хватает ли средств купить игрушку
     */
    boolean costCheck(double cost){
        return (getMoney() + cost <= getDeposit());
    }

    /**
     * сортировка игрушек по стоимости
     * @return возвращает отсортированный массив игрушек
     */
    public Toy[] sort(){

        Toy[] sorted = new Toy[getToys().size()];
        getToys().toArray(sorted);
        Comparator<Toy> comp = Comparator.comparingDouble(Toy::getCost);
        Arrays.sort(sorted, comp );
        return sorted;
    }

    public static Toy[] sort(ArrayList<Toy> ts){

        Toy[] sorted = new Toy[ts.size()];
        ts.toArray(sorted);
        Comparator<Toy> comp = Comparator.comparingDouble(Toy::getCost);
        Arrays.sort(sorted, comp);
        return sorted;
    }

    /**
     * поиск по диапазону стоимости
     * @param min
     * @param max
     * @return возвращает ArrayList с игрушками, находящимися в диапазоне
     */
    public ArrayList<Toy> search(double min, double max){

        ArrayList<Toy> result = new ArrayList<>();
        ArrayList<Toy> arr = getToys();
        for (int i=0; i < arr.size(); i++){
            if ((arr.get(i).getCost() <= max) && (arr.get(i).getCost() >= min)){
                result.add(arr.get(i));
            }
        }
        return result;
    }


    /**
     * методы создания экземпляров игрушек и добавления их в список
     */
    public void createBall(double cost, String type){
        if (costCheck(cost)) {
            addMoney(cost);
            Toy toy = new Ball(cost, type);
            addToy(toy);
        }else System.out.println("Недостаточно средств");
    }

    public void createDoll(double cost, String gender){
        if (costCheck(cost)){
            addMoney(cost);
            Toy toy = new Doll(cost, gender);
            addToy(toy);
        }else System.out.println("Недостаточно средств");
    }

    public void createCube(double cost, String color){
        if (costCheck(cost)) {
            addMoney(cost);
            Toy toy = new Cube(cost, color);
            addToy(toy);
        }else System.out.println("Недостаточно средств");
    }

    public void createSmallCar(double cost, String color, boolean collectionModel){
        if (costCheck(cost)) {
            addMoney(cost);
            Toy toy = new SmallCar(cost, color, collectionModel);
            addToy(toy);
        }else System.out.println("Недостаточно средств");
    }

    public void createMediumCar(double cost, String color, boolean rc){
        if (costCheck(cost)) {
            addMoney(cost);
            Toy toy = new MediumCar(cost, color, rc);
            addToy(toy);
        }else System.out.println("Недостаточно средств");
    }

    public void createBigCar(double cost, String color, boolean tipper){
        if (costCheck(cost)) {
            addMoney(cost);
            Toy toy = new BigCar(cost, color, tipper);
            addToy(toy);
        }else System.out.println("Недостаточно средств");
    }

    /**
     * Считать описание комнаты через файл
     */
    public void setDescription(String filename){
        ReadStream reader = new ReadStream(filename);
        reader.start();

        try {
            reader.join();
        }catch (InterruptedException e){
            System.out.println(e.getMessage());
        }

        System.out.println("Файл " + filename + " считан");
        this.description = reader.getJson();
    }

    /**
     * Запись данных в файл
     */
    public void writeFile(String filename, String data){
        WriteStream writer = new WriteStream(filename, data);
        writer.start();
    }

    /**
     * функции для вывода
     */
    public void printToys(){
        for(Toy r:toys){
            System.out.println(r.toString());
        }
    }

    public static void printToys(Toy[] ts){
        for(Toy r:ts){
            System.out.println(r.toString());
        }
    }

    public static void printToys(ArrayList<Toy> ts){
        for(Toy r:ts){
            System.out.println(r.toString());
        }
    }


    @Override
    public String toString() {
        return "PlayRoom: " +
                "deposit " + deposit +
                ", money " + money +
                " ,description " + description;
    }
}
