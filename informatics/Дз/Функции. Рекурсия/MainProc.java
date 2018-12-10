
public class MainProc {

	static String outTable = "0123456789abcdefghijklmnopqrstuvwxyz";

	public static void main(String[] args) {
		
		int p        = 3;
		int decValue = 123;
		
				
		System.out.print(decValue + "(10)=");
		makeConvert(decValue, p);
		System.out.println("(" + p + ")");

	}

	private static void makeConvert(int decValue, int p) {
		// Контроль допустимой системы счисления
		if(p >  outTable.length())
		{			
			System.out.print("error");
		}
		
		int mod    = decValue % p;
		int nexVal = decValue / p;
		
		// Рекурсивное вычисление старших разрядов
		if (nexVal > 0) {
			makeConvert(nexVal, p);			
		}
		
		if(mod < 10)
			// Просто для скорости
			System.out.print(mod);
		else
			// По правильному так
			System.out.print(outTable.substring(mod, mod + 1));
	}
	
}
