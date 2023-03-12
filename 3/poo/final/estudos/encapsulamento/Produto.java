package estudos.encapsulamento;

public class Produto {
    private String descricao;
    double preco;
    protected double precoBruto;
    public double calcularTotal(int quantidade) {
        return preco * quantidade;
    }
    void setDescricao(String descricao) {
        this.descricao = descricao;
    }
}