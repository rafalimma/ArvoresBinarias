int basic_op(char op, int value1, int value2) {
  int result;
  
  // Não é necessário usar um switch separado para converter 'op'.
  // Podemos usar diretamente o valor de 'op' para o switch.
  switch(op) {
    case '+':
      result = value1 + value2;
      break;
    case '-':
      result = value1 - value2;
      break;
    case '*':
      result = value1 * value2;
      break;
    case '/':
      result = value1 / value2;
      break;
    default:
      result = 0;  // Ou alguma outra forma de erro.
      break;
  }

  return result;
}