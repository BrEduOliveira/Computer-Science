public class AppFuncionario{
	public static void main(String[] args) {
		Funcionario func = new Funcionario("Bruno", 3000);

		System.out.printf("Nome: %s \nSalario: %.2f\n\n", func.getNome(), func.getSalario());
		func.setReajuste();
		System.out.printf("Apos o reajuste:\n\nNome: %s \nSalario: %.2f", func.getNome(), func.getSalario());

	}
}