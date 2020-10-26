package arquivo;

import cliente.*;

//Interface GerenciadorClientes
public interface GerenciadorClientes {
	public void gravarClientes(Cliente[] nome, int tam);
	public void lerClientes();
}