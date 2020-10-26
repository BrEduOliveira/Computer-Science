package cliente;

public class Cliente {
	//Atributo privado para o nome do cliente (só pode ser acessado pelo método acessador)
	private String nome;
	
	//Método construtor
	public Cliente(String nome) {
		this.nome = nome;
	}
	
	//Método acessador
	public String getNome() {
		return nome;
	}
	
	//Método modificador
	public void setNome(String nome) {
		this.nome = nome;
	}
}