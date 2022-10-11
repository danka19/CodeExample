import vegetables.*;

import java.io.FileInputStream;
import java.util.logging.Level;
import java.util.logging.LogManager;

public class Main {
	/**
	 * Объявление логгера и подрузка его параметров из файла
	 */
	static java.util.logging.Logger LOGGER;

	static {
		try(FileInputStream ins = new FileInputStream("log.config")){ //полный путь до файла с конфигами
			LogManager.getLogManager().readConfiguration(ins);
			LOGGER = java.util.logging.Logger.getLogger(Main.class.getName());
		}catch (Exception ignore){
			ignore.printStackTrace();
		}
	}

	public static void main(String[] args) {
		
		Chef chef = new Chef();

		LOGGER.log(Level.INFO,"Запуск приложения");
		chef.showOptions();
	}
}
