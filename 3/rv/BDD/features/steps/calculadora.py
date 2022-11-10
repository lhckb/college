from behave import *

from src.calc import Calculadora

# SOMA
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


# SUBTRACAO
@given("o primeiro operador é 9")
def set_op1(context):
    context.op1 = 9

@step("o segundo operador é 8")
def set_op2(context):
    context.op2 = 8


@when("eu subtrair os dois operadores")
def subtrair(context):
    calc = Calculadora()
    context.resultado = calc.subtrair(context.op1,context.op2)

@then("o resultado deve ser 1")
def result(context):
    assert context.resultado == 1


# DIVISAO
@given("o primeiro operador é 36")
def set_op1(context):
    context.op1 = 36

@step("o segundo operador é 6")
def set_op2(context):
    context.op2 = 6


@when("eu dividir os dois operadores")
def subtrair(context):
    calc = Calculadora()
    context.resultado = calc.dividir(context.op1,context.op2)

@then("o resultado deve ser 6")
def result(context):
    assert context.resultado == 6


# MULTIPLICACAO
@given("o primeiro operador é 19")
def set_op1(context):
    context.op1 = 36

@step("o segundo operador é 9")
def set_op2(context):
    context.op2 = 6


@when("eu multiplicar os dois operadores")
def subtrair(context):
    calc = Calculadora()
    context.resultado = calc.multiplicar(context.op1,context.op2)

@then("o resultado deve ser 171")
def result(context):
    assert context.resultado == 171


# POTENCIA
@given("o primeiro operador é 2")
def set_op1(context):
    context.op1 = 2

@step("o segundo operador é 15")
def set_op2(context):
    context.op2 = 15


@when("eu potenciar os dois operadores")
def subtrair(context):
    calc = Calculadora()
    context.resultado = calc.potencia(context.op1,context.op2)

@then("o resultado deve ser 32768")
def result(context):
    assert context.resultado == 32768