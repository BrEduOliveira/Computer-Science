public class Funcionario extends Pessoa{
	private double salario;

	public Funcionario(String nome, double salario){
		super(nome);
		this.salario = salario;
	}

	public double getSalario(){
		return salario;
	}

	public void setReajuste(){
		this.salario += (salario * 0.10);
	}
}