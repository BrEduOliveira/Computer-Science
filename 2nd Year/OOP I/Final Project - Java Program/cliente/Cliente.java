package cliente;

public class Cliente {
	//Atributo privado para o nome do cliente (s� pode ser acessado pelo m�todo acessador)
	private String nome;
	
	//M�todo construtor
	public Cliente(String nome) {
		this.nome = nome;
	}
	
	//M�todo acessador
	public String getNome() {
		return nome;
	}
	
	//M�todo modificador
	public void setNome(String nome) {
		this.nome = nome;
	}
}