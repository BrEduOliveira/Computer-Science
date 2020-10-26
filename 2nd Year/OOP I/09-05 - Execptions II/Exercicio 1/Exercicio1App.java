public class Exercicio1App {
	public static void main(String[] args) {
		ContaCorrente conta = new ContaCorrente();

		/* Testa a exce��o de valor negativo. */
		public static void throwException(){
			try {
				conta.depositar(100);
				conta.depositar(-50);
				throw new Exception();
			} catch (ValorNegativoException e) {
				System.out.println(e);
			}

			/* Testa a exce��o de saldo insuficiente. */ 
			try {
				conta.sacar(70);
				conta.sacar(50);
				throw new Exception();
			} catch (ValorNegativoException | SaldoInsuficienteException e) {
				System.out.println(e);
			}
		}
		System.out.println("Saldo final: R$ " + conta.getSaldo());
	}
}
