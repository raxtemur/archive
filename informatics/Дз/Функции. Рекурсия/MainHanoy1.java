
public class MainHanoy1 {

	public static void main(String[] args) {

		int amount = 5;
		
		move(amount, 1, 3);

	}
	
	// ����������� ��������� �������������� amount ������ �� ����� from �� ����� to 
	private static void move(int amount, int from, int to) {
		
		if (amount == 1) {
			System.out.println(amount + " " + from + " " + to);
		}
		else {
			// ���������� ��������� �����
			int empty = 1;
			
			if(from == 1 || to == 1) {
				if(from == 2 || to == 2)
					empty = 3;
				else
					empty = 2;
			}
			
			// ���������� K-1 �� ��������� �����
			move(amount - 1, from, empty);
			
			// ������������� ������
			System.out.println(amount + " " + from + " " + to);
			
			// ����������� K-1 �� ���������� �� ������
			move(amount - 1, empty, to);
		}
	}

}
