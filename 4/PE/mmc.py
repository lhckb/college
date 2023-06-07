import math
import statistics

ultimos_precos = [9, 8, 10, 13, 12, 15]

preco_hoje = 10
preco_ontem = 12

retorno_diario_periodido = math.log(preco_hoje / preco_ontem)

media_retorno_diario = sum(ultimos_precos) / len(ultimos_precos)

variancia = statistics.variance(ultimos_precos)

drift = media_retorno_diario - (variancia / 2)

valor_random = statistics.stdev(ultimos_precos)

preco_amanha = preco_hoje * math.e ** (drift + valor_random)

print(preco_amanha)