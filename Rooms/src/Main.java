import Rooms.*;

import java.io.FileInputStream;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.ArrayList;
import java.util.logging.LogManager;

public class Main {
    /**
     * Подключение логгера, который считывает свои параметры из файла (в файле указаны параметры записи в файл)
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

    public static void main(String[] args) {
        LOGGER.log(Level.INFO,"Начало main, запуск программы]");

        try{
            ArrayList<PlayRoom> rooms = new ArrayList<>();
            Menu.mainMenu(rooms);
        }
        catch (Exception e){
            LOGGER.log(Level.WARNING,"Аварийное завершение программы, ошибка " + e);
        }
    }
}
