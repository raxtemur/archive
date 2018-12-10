
public class MainHanoy1 {

	public static void main(String[] args) {

		int amount = 5;
		
		move(amount, 1, 3);

	}
	
	// Рекурсивная процедура перекладывания amount блинов со штыря from на штырь to 
	private static void move(int amount, int from, int to) {
		
		if (amount == 1) {
			System.out.println(amount + " " + from + " " + to);
		}
		else {
			// Определяем свободный штырь
			int empty = 1;
			
			if(from == 1 || to == 1) {
				if(from == 2 || to == 2)
					empty = 3;
				else
					empty = 2;
			}
			
			// Переложили K-1 на свободный штырь
			move(amount - 1, from, empty);
			
			// Перекладываем нижний
			System.out.println(amount + " " + from + " " + to);
			
			// Докладываем K-1 со свободного на нужный
			move(amount - 1, empty, to);
		}
	}

}
