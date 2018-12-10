
public class MainHanoy2 {
	
		static int count = 0;

		public static void main(String[] args) {

			int amount = 5;
			
			count = 0;
			
			if (amount > 0)
				move2(amount, 1, 3);
			else
				System.out.println("Количество дисков не может быть равно " + amount);
				
			// Для отладки (на 10 дисках алгоритм дает 24959 операций)
			System.out.println("Операций: " + count);

		}
		
		// Отображение перемещения диска
		private static void printOper(int pos, int from, int to) {
			System.out.println(pos + " " + from + " " + to);
			count++;
		}

		// Расчет следующей позиции
		private static int getNextPos(int curPos) {
			if (curPos == 3)
				return 1;
			else 
				return curPos + 1; 
		}
		
		// Расчет предыдущей позиции
		private static int getPrevPos(int curPos) {
			if (curPos == 1)
				return 3;
			else 
				return curPos - 1; 
		}
		
		// Рекурсивная процедура перекладывания amount блинов со штыря from на штырь to по кругу
		private static void move2(int amount, int from, int to) {
			
			int nextPos = getNextPos(from); 
			
			// Случай одного диска (выход из рекурсии)
			if (amount == 1) {
				printOper(amount, from, nextPos);
				
				if(nextPos != to)
					printOper(amount, nextPos, to);
			}
			else {
				// Перетаскиваем (amount - 1) на две позиции вперед (на предыдущую то бишь позицию)
				int prevPos = getPrevPos(from);
				move2(amount - 1, from, prevPos);
				
				// Подтягиваем на одну позицию нижний блин
				printOper(amount, from, nextPos);
				
				// Если мы уже в нужной точке
				if(nextPos == to) {
					move2(amount - 1, prevPos, to);
				}
				else // Нужно еще раз двинуть (amount - 1) на освободившуюся позицию от нижнего блина
				{
					move2(amount - 1, prevPos, from);
					
					// Устанавливаем на место нижний блин
					printOper(amount, nextPos, to);
					
					// Устанавливаем (amount - 1) на нижний блин
					move2(amount - 1, from, to);
				}
			}
		}
}
