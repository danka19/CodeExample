import Rooms.*;
import Toys.*;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.*;

/**
 * Класс, в котором реализованы методы управления программой через консоль
 */

public abstract class Menu {
    /**
     * Объявление логгера и подрузка его параметров из файла
     */
    static Logger LOGGER;
    static {
        try(FileInputStream ins = new FileInputStream("log.config")){ //полный путь до файла с конфигами
            LogManager.getLogManager().readConfiguration(ins);
            LOGGER = Logger.getLogger(Main.class.getName());
        }catch (Exception ignore){
            ignore.printStackTrace();
        }
    }

    //главное меню
    public static void mainMenu(ArrayList<PlayRoom> rooms){
        System.out.println("Главное меню");
        System.out.println("****************************************************************");
        System.out.println("1. Просмотреть список комнат");
        System.out.println("2. Выход");

        //переход
        int option = readOption();
        switch (option){
            case 1:
                roomList(rooms);
            case 2:
                LOGGER.log(Level.INFO,"Завершение программы");
                System.exit(0);
            default:{
                System.out.println("Неверное значение. Повторите ввод");
                mainMenu(rooms);
            }
        }
    }

    //меню со списком комнат
    public static void roomList(ArrayList<PlayRoom> rooms){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("1. Создать комнату");
        System.out.println("****************************************************************");
        System.out.println("Ваши комнаты:");
        int n = 1;
        for(PlayRoom r:rooms){
            n++;
            System.out.print(n + ". ");
            System.out.println(r.toString());
        }
        System.out.println("Чтобы войти в комнату введите её номер");

        //переход
        int option = readOption();
        switch (option){
            case 0:
                mainMenu(rooms);
            case 1:
                roomAddMenu(rooms);
            default:{
                if (option > 1 && option <= n){
                    roomMenu(rooms, option-2);
                }
            }
        }



    }

    //меню со списком игрушек
    public static void roomMenu(ArrayList<PlayRoom> rooms, int n){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("1. Добавить игрушку");
        System.out.println("2. Изменить сумму на комнату");
        System.out.println("3. Сортировать по стоимости игрушек");
        System.out.println("4. Вывести игрушки с интервале стоимости");
        System.out.println("5. Добавить описание комнаты из файла");
        System.out.println("6. Записать информацию о классе в файл");
        System.out.println("****************************************************************");
        System.out.println("Игрушки в комнате:");
        rooms.get(n).printToys();

        int option = readOption();
        switch (option){

            case 0:
                mainMenu(rooms);
                break;

            case 1:
                toyAddMenu(rooms, n);
                break;

            case 2:
                System.out.println("Введите новую ссумму");
                double sum = readSum();
                rooms.get(n).setDeposit(sum);
                LOGGER.log(Level.INFO,"Изменение суммы в комнате");
                mainMenu(rooms);
                break;

            case 3:
                Toy[] toysArr = rooms.get(n).sort();
                PlayRoom.printToys(toysArr);
                mainMenu(rooms);
                break;

            case 4:
                System.out.println("Введите через 'ENTER' минимальное и максимальное значения диапазона");
                double min = readSum();
                double max = readSum();
                ArrayList<Toy> toysArrList = rooms.get(n).search(min, max);
                PlayRoom.printToys(toysArrList);
                mainMenu(rooms);
                break;

            case 5:
                System.out.println("Введите название файла");
                String fn = readLine();
                rooms.get(n).setDescription(fn);
                LOGGER.log(Level.INFO,"Обновление описания комнаты из файла " + fn);
                mainMenu(rooms);
                break;

            case 6:
                System.out.println("Введите название файла");
                String fn1 = readLine();
                rooms.get(n).writeFile(fn1, rooms.get(n).toString());
                LOGGER.log(Level.INFO,"Информация о комнате была записана в файл " + fn1);
                mainMenu(rooms);
                break;

            default:
                System.out.println("Неверное значение. Повторите ввод");
                mainMenu(rooms);
        }
    }

    //меню выбора типа игрушки
    public static void toyAddMenu(ArrayList<PlayRoom> rooms, int n){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("1. Мяч");
        System.out.println("2. Кукла");
        System.out.println("3. Куб");
        System.out.println("4. Маленькая машина");
        System.out.println("5. Средняя машина");
        System.out.println("6. Большая машина");

        int option = readOption();
        switch (option){
            case 0:
                mainMenu(rooms);
                break;
            case 1:
                addBall(rooms, n);
                break;
            case 2:
                addDoll(rooms, n);
                break;
            case 3:
                addCube(rooms, n);
                break;
            case 4:
                addSmallCar(rooms, n);
                break;
            case 5:
                addMediumCar(rooms, n);
                break;
            case 6:
                addBigCar(rooms, n);
                break;
            default:{
                System.out.println("Неверное значение. Повторите ввод");
                mainMenu(rooms);
            }
        }
    }

    //меню выбора типа комнаты
    public static void roomAddMenu(ArrayList<PlayRoom> rooms){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("1. Комната для маленьких");
        System.out.println("2. Комната для средних");

        int option = readOption();
        switch (option){
            case 0:
                mainMenu(rooms);
                break;
            case 1:
                smallRoomAdd(rooms);
                break;
            case 2:
                mediumRoomAdd(rooms);
                break;
            default:{
                System.out.println("Неверное значение. Повторите ввод");
                mainMenu(rooms);
            }
        }
    }

    // Меню получения данных для создания новой малой комнаты
    public static void smallRoomAdd(ArrayList<PlayRoom> rooms){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите сумму, на которую будут закупаться игрушки в комнате");

        double sum = readSum();
        if (sum == 0) {
        }
        else {
            PlayRoomForSmall room = new PlayRoomForSmall(sum);
            rooms.add(room);
            LOGGER.log(Level.INFO,"Создание маленькой комнаты на сумму " + sum);
        }
        mainMenu(rooms);
    }

    // Меню получения данных для создания новой средней комнаты
    public static void mediumRoomAdd(ArrayList<PlayRoom> rooms){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите сумму, на которую будут закупаться игрушки в комнате");

        double sum = readSum();
        if (sum == 0) {
        }
        else {
            PlayRoomForMedium room = new PlayRoomForMedium(sum);
            rooms.add(room);
            LOGGER.log(Level.INFO,"Создание средней комнаты на сумму " + sum);
        }
        mainMenu(rooms);
    }

    //далее представлены методы, запрашивающие информацию для создания той или иной игрушки и вызывающие соотв. методы из класса PlayRoom
    public static void addBall(ArrayList<PlayRoom> rooms, int n){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите через 'ENTER' такие параметры как:");
        System.out.println("1) Стоимость\n2) Тип (прим: баскетбольный)");

        double sum = readSum();
        if (sum != 0) {
            String type = readLine();
            rooms.get(n).createBall(sum, type);
            LOGGER.log(Level.INFO,"Создание игрушки 'МЯЧ' с параметрами " + sum + ", " + type);
        }
        mainMenu(rooms);
    }

    public static void addDoll(ArrayList<PlayRoom> rooms, int n){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите через 'ENTER' такие параметры как:");
        System.out.println("1) Стоимость\n2) Пол (прим: женский)");

        double sum = readSum();
        if (sum != 0) {
            String gender = readLine();
            rooms.get(n).createDoll(sum, gender);
            LOGGER.log(Level.INFO,"Создание игрушки 'КУКЛА' с параметрами " + sum + ", " + gender);
        }
        mainMenu(rooms);
    }

    public static void addCube(ArrayList<PlayRoom> rooms, int n){System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите через 'ENTER' такие параметры как:");
        System.out.println("1) Стоимость\n2) Цвет");

        double sum = readSum();
        if (sum != 0) {
            String color = readLine();
            rooms.get(n).createCube(sum, color);
            LOGGER.log(Level.INFO,"Создание игрушки 'КУБ' с параметрами " + sum + ", " + color);
        }
        mainMenu(rooms);
    }

    public static void addSmallCar(ArrayList<PlayRoom> rooms, int n){System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите через 'ENTER' такие параметры как:");
        System.out.println("1) Стоимость\n2) Цвет\n3) Является ли эта модель коллекционной? (true/false)");

        double sum = readSum();
        if (sum != 0) {
            String color = readLine();
            boolean bool = readBool();
            rooms.get(n).createSmallCar(sum, color, bool);
            LOGGER.log(Level.INFO,"Создание игрушки 'МАЛЕНЬКАЯ МАШИНА' с параметрами " + sum + ", " + color + ", " + bool);
        }
        mainMenu(rooms);
    }

    public static void addMediumCar(ArrayList<PlayRoom> rooms, int n){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите через 'ENTER' такие параметры как:");
        System.out.println("1)Стоимость\n2)Цвет\n3) Является ли эта модель радиоуправляемой? (true/false)");

        double sum = readSum();
        if (sum != 0) {
            String color = readLine();
            boolean bool = readBool();
            rooms.get(n).createMediumCar(sum, color, bool);
            LOGGER.log(Level.INFO,"Создание игрушки 'СРЕДНЯЯ МАШИНА' с параметрами " + sum + ", " + color + ", " + bool);
        }
        mainMenu(rooms);
    }

    public static void addBigCar(ArrayList<PlayRoom> rooms, int n){
        System.out.println("----------------------------------------------------------------");
        System.out.println("0. Главное меню");
        System.out.println("Введите через 'ENTER' такие параметры как:");
        System.out.println("1)Стоимость\n2)Цвет\n3) Является ли эта модель самосвалом? (true/false)");

        double sum = readSum();
        if (sum != 0) {
            String color = readLine();
            boolean bool = readBool();
            rooms.get(n).createBigCar(sum, color, bool);
            LOGGER.log(Level.INFO,"Создание игрушки 'БОЛЬШАЯ МАШИНА' с параметрами " + sum + ", " + color + ", " + bool);
        }
        mainMenu(rooms);
    }

    //Считыватели
    public static int readOption(){
        Scanner scan = new Scanner(System.in);
        int option = -1;
        option = scan.nextInt();
        return option;
    }

    public static double readSum(){
        Scanner scan = new Scanner(System.in);
        double option = -1;
        option = scan.nextDouble();
        return option;
    }

    public static String readLine(){
        Scanner scan = new Scanner(System.in);
        String option = "";
        option = scan.nextLine();
        return option;
    }

    public static boolean readBool(){
        Scanner scan = new Scanner(System.in);
        boolean option = false;
        option = scan.nextBoolean();
        return option;
    }
}
