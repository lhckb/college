from behave import *

from src.calc import Calculadora

@given("o primeiro operador é {operador1}")
def set_op1(context, operador1):
    context.op1 = int(operador1)

@step("o segundo operador é {operador2}")
def set_op2(context, operador2):
    context.op2 = int(operador2)


@when("eu somar os dois operadores")
def somar(context):
    calc = Calculadora()
    context.resultado = calc.somar(context.op1,context.op2)

@when("eu subtrair os dois operadores")
def somar(context):
    calc = Calculadora()
    context.resultado = calc.subtrair(context.op1,context.op2)

@when("eu dividir os dois operadores")
def somar(context):
    calc = Calculadora()
    context.resultado = calc.dividir(context.op1,context.op2)

@when("eu multiplicar os dois operadores")
def somar(context):
    calc = Calculadora()
    context.resultado = calc.multiplicar(context.op1,context.op2)

@when("eu potenciar os dois operadores")
def somar(context):
    calc = Calculadora()
    context.resultado = calc.potencia(context.op1,context.op2)

@then("o resultado deve ser {resultado}")
def result(context, resultado):
    assert context.resultado == int(resultado)
