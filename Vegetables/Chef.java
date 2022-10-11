package vegetables;

import com.sun.tools.javac.Main;

import java.io.FileInputStream;
import java.lang.reflect.Constructor;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.LogManager;


/**
 * Данный класс реализовывает основную логику программы.
 * Содержит методы по созданию салата и управления овощами
 */
public class Chef {

	/**
	 * Объявление логгера и подрузка его параметров из файла
	 */
	static java.util.logging.Logger logger1;

	static {
		try(FileInputStream ins = new FileInputStream("log.config")){ //полный путь до файла с конфигами
			LogManager.getLogManager().readConfiguration(ins);
			logger1 = java.util.logging.Logger.getLogger(Main.class.getName());
		}catch (Exception ignore){
			ignore.printStackTrace();
		}
	}

	private String name; // Имя шефа
	private Salad salad; // Салат, который мы готовим

	/**
	 * Конструктор по умолчанию
	 */
	public Chef() {
		name = "Адриано";
		salad = new Salad();
	}
	
	/**
	 * Конструктор с параметром имени шефа
	 */
	public Chef(String name) {
		this.name = name;
		salad = new Salad();
	}
	
	/**
	 * Конструктор с параметром имени шефа и салатом
	 */
	public Chef(String name, Salad salad) {
		this.name = name;
		this.salad = salad;
	}
	
	/**
	 * создает ингридиент с помощью параметров, которые ввел пользователь
	 * Возвращает ошибку, если ингридиент не был создан
	 */
	public Vegetable getIngredient(Scanner scanner) {
		String ingredientName;
		double weight;
		
		System.out.println("Введите название ингридиента:");
		ingredientName = scanner.next();
		
		System.out.println("Вес ингридиента (в грамммах):");
		
		try {
			weight = scanner.nextDouble();
		}
		catch (InputMismatchException e) {
			System.out.println("Неверный вес!");
			scanner.next();
			
			return null;
		}
		
		// Создает новый овощ используя вводимые данные
		try {
			Class [] parameters = {double.class};
			ingredientName = "vegetables." + ingredientName;
			Class ingredientClass = Class.forName(ingredientName);
			Constructor constructor =
					ingredientClass.getDeclaredConstructor(parameters);
			Vegetable vegetable = (Vegetable) constructor.newInstance(
					new Object[]{weight});
			
			return vegetable;
		}
		catch (Exception e) {
			System.out.println("Такого ингридиента не существует!");
			
			return null;
		}
	}
	
	/**
	 * Выводит ингридиенты в заданом диапазоне калорий
	 * @param Scanner lowerCalories, upperCalories - пользователь вводит значения калорий, в диапазоне которых программа выводит ингридиенты
	 */
	public void showIngredientsForCalories(Scanner scanner) {
		double lowerCalories, upperCalories;
		
		System.out.println("Введите минимальное значение:");
		try {
			lowerCalories = scanner.nextDouble();
		}
		catch (InputMismatchException e) {
			System.out.println("Ошибка Ввода!");
			scanner.next();
			
			return;
		}
		
		System.out.println("Введите максимальное значение:");
		try {
			upperCalories = scanner.nextDouble();
		}
		catch (InputMismatchException e) {
			System.out.println("Ошибка Ввода!");
			scanner.next();
			
			return;
		}
		
		salad.showIngredientsByCalories(lowerCalories, upperCalories);
	}
	
	/**
	 * Меню. Выводит возможные варианты выбора для пользователя
	 */
	public void showOptions() {
		Scanner scanner = new Scanner(System.in);
		int choice = -1;
		Vegetable vegetable = null;
		
		System.out.println("Доброго времени суток! Меня зовут " + name + ".");
		System.out.println("Что бы вы хотели сегодня приготовить?");
		
		while (choice != 0) {
			System.out.println("\nВыберите номер опции:");
			System.out.println("1. Переименовать салат");
			System.out.println("2. Показать рецепт");
			System.out.println("3. Добавить ингридиент");
			System.out.println("4. Сортировать ингридиенты по калориям");
			System.out.println("5. Сортировать ингридиенты по весу");
			System.out.println("6. Показать ингридиенты в диапазоне калорий");
			System.out.println("7. Добавить описание салату из файла");
			System.out.println("8. Записать рецепт в файл");
			System.out.println("0. Выход");
			
			try {
				choice = scanner.nextInt();
			}
			catch (InputMismatchException e) {
				System.out.println("Неверная опция!");
				scanner.next();
				choice = -1;
			}
			
			switch(choice) {
				case 1:
					System.out.println("Назовите свой салат:");
					salad.setname(scanner.next());
					logger1.log(Level.INFO,"Дано новое название салату ");
					break;
				
				case 2:
					salad.showRecipe();
					break;
				
				case 3:
					vegetable = getIngredient(scanner);
					if (vegetable != null) {
						if (!salad.addIngredient(vegetable)) {
						System.out.println("Невозможно добавить ингридиент!");
						}
						logger1.log(Level.INFO,"Добавлен ингридиент " + vegetable.getName());
					}
					break;
				
				case 4:
					salad.sortIngredientsByCalories();
					logger1.log(Level.INFO,"Салат отсортирован по калориям");
					break;
				
				case 5:
					salad.sortIngredientsByWeight();
					logger1.log(Level.INFO,"Салат отсортирован по весу");
					break;
				
				case 6:
					showIngredientsForCalories(scanner);
					break;

				case 7:
					System.out.println("Введите название файла");
					String fn = scanner.next();
					salad.setDescription(fn);
					logger1.log(Level.INFO,"Обновление описания комнаты из файла " + fn);
					break;

				case 8:
					System.out.println("Введите название файла");
					String fn1 = scanner.next();
					salad.writeFile(fn1, salad.toString());
					logger1.log(Level.INFO,"Рецепт записан в файл " + fn1);
					break;


				case 0:
					logger1.log(Level.INFO,"Завершение программы");
					System.exit(0);
					break;

				default:
					break;
			}
		}
		scanner.close();
	}
}