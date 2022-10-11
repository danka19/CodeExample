package vegetables;

import stream_file.ReadStream;
import stream_file.WriteStream;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Данный класс реализует методы по добавлению, сортировке и выводу на экран ингредиентов (овощей)
 */
public class Salad {
	private String name; // the name of the salad
	private List<Vegetable> ingredients = new ArrayList<Vegetable>();
	private String description;
	
	/**
	 * Конструктор по умолчанию
	 */
	public Salad() {
		name = "Неизвестно";
	}
	
	/**
	 * Конструктор с параметром имени
	 */
	public Salad(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public List<?> getIngredients() {
		return ingredients;
	}
	
	public void setname(String name) {
		this.name = name;
	}
	
	public boolean addIngredient(Vegetable vegetable) {
		return ingredients.add(vegetable);
	}
	
	public void showRecipe() {
		if (ingredients.isEmpty()) {
			System.out.println("Вы еще не добавили ни одного ингредиента!");
			
			return;
		}
		
		System.out.println("Салат " + name + " содержит:");
		for (Vegetable vegetable : ingredients) {
			System.out.println(vegetable.toString());
		}
		System.out.println("----------------------------");
		System.out.println("Итоговая энергетическая ценность: " + countCalories() + "Ккал");
	}

	/**
	 *
	 * @return - возвращает калории в салате
	 */
	public double countCalories() {
		double calories = 0.0;
		
		for (Vegetable vegetable : ingredients) {
			calories += vegetable.getTotalCalories();
		}
		
		return calories;
	}

	public static double countCalories(List<Vegetable> vegetables_) {
		double calories = 0.0;

		for (Vegetable vegetable : vegetables_) {
			calories += vegetable.getTotalCalories();
		}

		return calories;
	}
	
	public void sortIngredientsByCalories() {
		Collections.sort(ingredients, new CaloriesComparator());
	}
	
	public void sortIngredientsByWeight() {
		Collections.sort(ingredients, new WeightComparator());
	}


	public void showIngredientsByCalories(double lowerCalories,
			                              double upperCalories) {
		double calories;
		
		System.out.println("Ингредиенты по категориям ["
				+ lowerCalories + ", " + upperCalories + "]");
		for (Vegetable vegetable : ingredients) {
			calories = vegetable.getCalories();
			if (calories >= lowerCalories && calories <= upperCalories) {
				System.out.println(vegetable.getName() + ", "
						+ vegetable.getCalories() + "Ккал на 100г");
			}
		}
	}

	/**
	 * Добавить описание салата через файл
	 * @param filename - название файла, из которого будут считываться данные
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
	 * @param filename, data - на вход название файла, куда будут записываться данные, а также сами данные для записи
	 */
	public void writeFile(String filename, String data){
		WriteStream writer = new WriteStream(filename, data);
		writer.start();
	}

	@Override
	public String toString() {
		return "Salad: " +
				"name=" + name +
				", ingredients=" + ingredients +
				", description=" + description ;
	}
}