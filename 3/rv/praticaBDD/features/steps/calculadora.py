from behave import *

from scr.calc import Calculadora


@given("o primeiro operador é 3")
def set_op1(context):
    context.op1 = 3

@step("o segundo operador é 2")
def set_op2(context):
    context.op2 = 2


@when("eu somar os dois operadores")
def somar(context):
    calc = Calculadora()
    context.resultado = calc.somar(context.op1,context.op2)

@then("o resultado deve ser 5")
def result(context):
    assert context.resultado == 5


@given("o primeiro operador é {operador1}")
def set_operador1(context, operador1):
    context.op1 = int(operador1)


@step("o segundo operador é {operador2}")
def set_operador2(context, operador2):
    context.op2 = int(operador2)


@then("o resultado deve ser {resultado}")
def resultado(context, resultado):
    assert context.resultado == int(resultado)