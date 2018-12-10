
public class MainHanoy2 {
	
		static int count = 0;

		public static void main(String[] args) {

			int amount = 5;
			
			count = 0;
			
			if (amount > 0)
				move2(amount, 1, 3);
			else
				System.out.println("���������� ������ �� ����� ���� ����� " + amount);
				
			// ��� ������� (�� 10 ������ �������� ���� 24959 ��������)
			System.out.println("��������: " + count);

		}
		
		// ����������� ����������� �����
		private static void printOper(int pos, int from, int to) {
			System.out.println(pos + " " + from + " " + to);
			count++;
		}

		// ������ ��������� �������
		private static int getNextPos(int curPos) {
			if (curPos == 3)
				return 1;
			else 
				return curPos + 1; 
		}
		
		// ������ ���������� �������
		private static int getPrevPos(int curPos) {
			if (curPos == 1)
				return 3;
			else 
				return curPos - 1; 
		}
		
		// ����������� ��������� �������������� amount ������ �� ����� from �� ����� to �� �����
		private static void move2(int amount, int from, int to) {
			
			int nextPos = getNextPos(from); 
			
			// ������ ������ ����� (����� �� ��������)
			if (amount == 1) {
				printOper(amount, from, nextPos);
				
				if(nextPos != to)
					printOper(amount, nextPos, to);
			}
			else {
				// ������������� (amount - 1) �� ��� ������� ������ (�� ���������� �� ���� �������)
				int prevPos = getPrevPos(from);
				move2(amount - 1, from, prevPos);
				
				// ����������� �� ���� ������� ������ ����
				printOper(amount, from, nextPos);
				
				// ���� �� ��� � ������ �����
				if(nextPos == to) {
					move2(amount - 1, prevPos, to);
				}
				else // ����� ��� ��� ������� (amount - 1) �� �������������� ������� �� ������� �����
				{
					move2(amount - 1, prevPos, from);
					
					// ������������� �� ����� ������ ����
					printOper(amount, nextPos, to);
					
					// ������������� (amount - 1) �� ������ ����
					move2(amount - 1, from, to);
				}
			}
		}
}
