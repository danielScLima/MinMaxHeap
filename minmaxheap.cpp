#include "minmaxheap.h"
#include <math.h>
#include <string>

MinMaxHeap::MinMaxHeap()
{
    numbers.push_back(-1); //Fake position
}

MinMaxHeap::~MinMaxHeap()
{
    numbers.clear();
}

int MinMaxHeap::getNumberOfElementsInTheVector()
{
    return numbers.size()-1;
}

std::vector<int> MinMaxHeap::getHeapAsAVector()
{
    std::vector<int> numbers2(numbers);
    numbers2.erase(numbers2.begin()+0);
    return numbers2;
}

ColorRepresentation MinMaxHeap::getColorIndex(int realPosition)
{
    int myLevel = getLevelFromPosition(realPosition);
    if (myLevel % 2 == 1) //impar - nível de mínimo
    {
        return ColorRepresentation::BLUE;
    }
    else //nível de máximo
    {
        return ColorRepresentation::RED;
    }
}

int MinMaxHeap::realToVirtual(int realPosition)
{
    return realPosition - 1;
}

int MinMaxHeap::virtualToReal(int virtualPosition)
{
    return virtualPosition + 1;
}

void MinMaxHeap::insertInterface(int number)
{
    int position = insert(number);
    upsideCheckAndMove(position);
}

int MinMaxHeap::insert(int number)
{
    int size = this->numbers.size();
    this->numbers.push_back(number);
    return size;
}

int MinMaxHeap::getLevelFromPosition(int realPos)
{
    //Posições começam do 1
    for (int index = 1; true; ++index)
    {
        if (realPos < pow(2, index))
            return index;

        if (index == 99999) //Para evitar absurdos
            break;
    }
    return -1;
}

void MinMaxHeap::upsideCheckAndMove(int realPos)
{
    int tmpRealPos = realPos;
    int alreadyComparedWithFather = false;
    while (tmpRealPos > 1)
    {
        if (alreadyComparedWithFather == false) //para clareza
        {
            //Comparando com o pai
            int fatherRealPosition = getFatherRealPosition(tmpRealPos);
            if (fatherRealPosition < 1)
                return;

            int myLevel = getLevelFromPosition(tmpRealPos);

            if (myLevel % 2 == 1) //impar - nível de mínimo
            {
                //por ser nível de mínimo, se for maior, troca
                if
                (
                    this->numbers.at(tmpRealPos) >
                    this->numbers.at(fatherRealPosition)
                )
                {
                    int temp = numbers[fatherRealPosition];
                    numbers[fatherRealPosition] = numbers[tmpRealPos];
                    numbers[tmpRealPos] = temp;

                    tmpRealPos = fatherRealPosition;

                    //por ter havido uma troca, ainda deve comparar
                    //com o outro pai. Assim, alreadyComparedWithFather
                    //continua com false
                }
                else
                {
                    alreadyComparedWithFather = true;
                    //tmpRealPos = fatherRealPosition;
                }
            }
            else //par - é um nível de máximo
            {
                //por ser nível de máximo, se for menor, troca
                if
                (
                    this->numbers.at(tmpRealPos) <
                    this->numbers.at(fatherRealPosition)
                )
                {
                    int temp = numbers[fatherRealPosition];
                    numbers[fatherRealPosition] = numbers[tmpRealPos];
                    numbers[tmpRealPos] = temp;

                    tmpRealPos = fatherRealPosition;

                    //por ter havido uma troca, ainda deve comparar
                    //com o outro pai. Assim, alreadyComparedWithFather
                    //continua com false
                }
                else
                {
                    alreadyComparedWithFather = true;
                    //tmpRealPos = fatherRealPosition;
                }
            }
        } //fim de já comparou com pai
        else //comparar com o avô
        {
            //Comparando com o pai
            int fatherRealPosition = getFatherRealPosition(tmpRealPos);
            if (fatherRealPosition < 1)
                return;
            int grandpaRealPosition = getFatherRealPosition(fatherRealPosition);
            if (grandpaRealPosition < 1)
                return;

            int myLevel = getLevelFromPosition(tmpRealPos);

            if (myLevel % 2 == 1) //impar - nível de mínimo
            {
                //Se é um nível de mínimo, o avô deve ser menor
                //que este nível. Se o avô for maior, troca
                if
                (
                    this->numbers.at(tmpRealPos) <
                    this->numbers.at(grandpaRealPosition)
                )
                {
                    int temp = numbers[grandpaRealPosition];
                    numbers[grandpaRealPosition] = numbers[tmpRealPos];
                    numbers[tmpRealPos] = temp;

                    tmpRealPos = grandpaRealPosition;
                }
                else //Não precisa mais verificar
                    break;
            }
            else //par - nível de máximo
            {
                //se é um nível de máximo, o avô deve ser maior.
                //se o avô for menor, troca
                if
                (
                    this->numbers.at(tmpRealPos) >
                    this->numbers.at(grandpaRealPosition)
                )
                {
                    int temp = numbers[grandpaRealPosition];
                    numbers[grandpaRealPosition] = numbers[tmpRealPos];
                    numbers[tmpRealPos] = temp;

                    tmpRealPos = grandpaRealPosition;
                }
                else //Não precisa mais verificar
                    break;
            }
        }
    }
}

int MinMaxHeap::leftChildRealPos(int realPosition)
{
    return 2 * realPosition;
}

int MinMaxHeap::rightChildRealPos(int realPosition)
{
    return 2 * realPosition + 1;
}

int MinMaxHeap::getFatherRealPosition(int realPosition)
{
    return floor(realPosition / 2);
}

const std::string MinMaxHeap::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (numbers.size() == 1) //just fake number
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        for (int index = 1; index < numbers.size(); ++index)
        {
            textToFile += std::to_string(numbers[index])+";";
        }
        for (int index = 1; index < numbers.size(); ++index)
        {
            int leftChildRealPoNumber = leftChildRealPos(index);

            if (leftChildRealPoNumber < numbers.size())
            {
                textToFile += std::to_string(numbers[index])+"->"+
                        std::to_string(numbers[leftChildRealPoNumber])+";";
            }

            int rightChildRealPoNumber = rightChildRealPos(index);
            if (rightChildRealPoNumber < numbers.size())
            {
                textToFile += std::to_string(numbers[index])+"->"+
                        std::to_string(numbers[rightChildRealPoNumber])+";";
            }
        }
        textToFile += "Root->"+std::to_string(numbers[1])+";";
    }

    textToFile += "}";

    return textToFile;
}


const std::string MinMaxHeap::gitDotFileMode12()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (numbers.size() == 1) //just fake number
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        for (int index = 1; index < numbers.size(); ++index)
        {
            textToFile += std::to_string(numbers[index]);
            if (getColorIndex(index) == ColorRepresentation::RED)
               textToFile += "[color = red style=filled fontcolor=white ];";
            else
               textToFile += "[color = lightblue style=filled ];";
        }
        for (int index = 1; index < numbers.size(); ++index)
        {
            int leftChildRealPoNumber = leftChildRealPos(index);

            if (leftChildRealPoNumber < numbers.size())
            {
                textToFile += std::to_string(numbers[index])+"->"+
                        std::to_string(numbers[leftChildRealPoNumber])+";";
            }

            int rightChildRealPoNumber = rightChildRealPos(index);
            if (rightChildRealPoNumber < numbers.size())
            {
                textToFile += std::to_string(numbers[index])+"->"+
                        std::to_string(numbers[rightChildRealPoNumber])+";";
            }
        }
        textToFile += "Root->"+std::to_string(numbers[1])+";";
    }

    textToFile += "}";

    return textToFile;
}

//Returns the sun position
int MinMaxHeap::getTheValidChildPositionWithSmallerValue(int fatherPosition)
{
    int size = numbers.size();
    if (fatherPosition >= size)
        return -1;

    int leftPos = leftChildRealPos(fatherPosition);
    int rightPos = rightChildRealPos(fatherPosition);

    if (leftPos >= size && rightPos >= size)
    {
        return -1;
    }
    else if (rightPos >= size)
    {
        return leftPos;
    }
    else
    {
        int smaller = leftPos;
        if (numbers[rightPos] < numbers[smaller])
            smaller = rightPos;

        return smaller;
    }
}

//Returns the sun position
int MinMaxHeap::getTheValidChildPositionWithHigestValue(int fatherPosition)
{
    int size = numbers.size();
    if (fatherPosition >= size)
        return -1;

    int leftPos = leftChildRealPos(fatherPosition);
    int rightPos = rightChildRealPos(fatherPosition);

    if (leftPos >= size && rightPos >= size)
    {
        return -1;
    }
    else if (rightPos >= size)
    {
        return leftPos;
    }
    else
    {
        int higest = leftPos;
        if (numbers[rightPos] > numbers[higest])
            higest = rightPos;

        return higest;
    }
}

int MinMaxHeap::getTheValidGrandsonPositionWithSmallerValue(int fatherPosition)
{
    int size = numbers.size();
    if (fatherPosition >= size)
        return -1;

    int leftPos = leftChildRealPos(fatherPosition);
    int rightPos = rightChildRealPos(fatherPosition);

    int gransonLeftLeft = -1;
    int gransonLeftRight = -1;
    int gransonRightLeft = -1;
    int gransonRightRight = -1;

    if (leftPos < size)
    {
        gransonLeftLeft = leftChildRealPos(leftPos);
        gransonLeftLeft = gransonLeftLeft < size? gransonLeftLeft:-1;

        gransonLeftRight = rightChildRealPos(leftPos);
        gransonLeftRight = gransonLeftRight < size? gransonLeftRight:-1;
    }

    if (rightPos < size)
    {
        gransonRightLeft = leftChildRealPos(rightPos);
        gransonRightLeft = gransonRightLeft < size? gransonRightLeft:-1;

        gransonRightRight = rightChildRealPos(rightPos);
        gransonRightRight = gransonRightRight < size? gransonRightRight:-1;
    }

    int smaller = -1;

    if (gransonLeftLeft == -1)
        smaller = -1;
    else
    {
        if (gransonLeftLeft < size)
            smaller = gransonLeftLeft;
        else
            return smaller;

        if (gransonLeftRight == -1)
            return smaller;
        else
        {
            if (numbers[gransonLeftRight] < numbers[smaller])
                smaller = gransonLeftRight;

            if (gransonRightLeft == -1)
                return smaller;
            {
                if (numbers[gransonRightLeft] < numbers[smaller])
                    smaller = gransonRightLeft;

                if (gransonRightRight == -1)
                    return smaller;
                else
                {
                    if (numbers[gransonRightRight] < numbers[smaller])
                        smaller = gransonRightRight;
                }
            }
        }
    }

    return smaller;
}

int MinMaxHeap::getTheValidGrandsonPositionWithHigestValue(int fatherPosition)
{
    int size = numbers.size();
    if (fatherPosition >= size)
        return -1;

    int leftPos = leftChildRealPos(fatherPosition);
    int rightPos = rightChildRealPos(fatherPosition);

    int gransonLeftLeft = -1;
    int gransonLeftRight = -1;
    int gransonRightLeft = -1;
    int gransonRightRight = -1;

    if (leftPos < size)
    {
        gransonLeftLeft = leftChildRealPos(leftPos);
        gransonLeftRight = rightChildRealPos(leftPos);
    }

    if (rightPos < size)
    {
        gransonRightLeft = leftChildRealPos(rightPos);
        gransonRightRight = rightChildRealPos(rightPos);
    }

    int higest = -1;

    if (gransonLeftLeft == -1)
        higest = -1;
    else
    {
        if (gransonLeftLeft < size)
            higest = gransonLeftLeft;
        else
            return higest;

        if (gransonLeftRight == -1)
            return higest;
        else
        {
            if (numbers[gransonLeftRight] > numbers[higest])
                higest = gransonLeftRight;

            if (gransonRightLeft == -1)
                return higest;
            {
                if (numbers[gransonRightLeft] > numbers[higest])
                    higest = gransonRightLeft;

                if (gransonRightRight == -1)
                    return higest;
                else
                {
                    if (numbers[gransonRightRight] > numbers[higest])
                        higest = gransonRightRight;
                }
            }
        }
    }

    return higest;
}

int MinMaxHeap::removeTheSmallerNumber()
{
    int swap = 0;
    int size = numbers.size();
    if (size < 2) return -1; //è dois, pois não tem menor se não tiver o el 1

    int removedNumber = numbers[1];
    numbers[1] = numbers.back();
    numbers.pop_back(); //remove o ultimo elemento

    int startOfRemoveSmaller = 1;
    moveDownside(startOfRemoveSmaller);

    return removedNumber;
}

int MinMaxHeap::removeTheHiguestNumber()
{
    int swap = 0;
    int size = numbers.size();
    if (size < 2) return -1;

    int startOfRemoveHigest = 0;
    if (size == 2)
        startOfRemoveHigest = 1; //o maior coincide com o menor
    if (size == 3)
        startOfRemoveHigest = 2; //the higest é o da posição 2
    if (size >= 4)
    {
        //verificar se o menor é o da posição 2 ou 3
        startOfRemoveHigest = 2;
        if (numbers[3] > numbers[startOfRemoveHigest])
            startOfRemoveHigest = 3;
    }

    int removedNumber = numbers[startOfRemoveHigest];
    numbers[startOfRemoveHigest] = numbers.back();
    numbers.pop_back(); //remove o ultimo elemento

    moveDownside(startOfRemoveHigest);

    return removedNumber;
}

void MinMaxHeap::moveDownside(int position)
{
    int size = numbers.size(); //atualiza o tamanho
    int swap = 0;

    int index = position;
    int smallerChildPos = 0;
    int higestChildPos = 0;
    int smallerGrandsonPos = 0;
    int higestGrandSon = 0;

    int alreadyComparedWithChilds = 0;
    while (index < size)
    {
        if (alreadyComparedWithChilds == 0) //deve comparar com filhos
        {
            int myLevel = getLevelFromPosition(index);
            if (myLevel % 2 == 1) //impar - nível de mínimo
            {
                //Deve ser menor que os seus filhos
                //Obtem o menor filho
                //Se o filho for menor que ele, faz a troca
                smallerChildPos = getTheValidChildPositionWithSmallerValue(index);
                if (smallerChildPos == -1)
                    break;

                //Verifica se deve fazer a troca
                if (numbers[index] > numbers[smallerChildPos])
                {
                    swap = numbers[index];
                    numbers[index] = numbers[smallerChildPos];
                    numbers[smallerChildPos] = swap;

                    //index = smallerChildPos;
                    //não altera o alreadyComparedWithChilds
                }
                else
                    alreadyComparedWithChilds = 1;
            } //fim de nível de mínimo
            else //par: nível de máximo
            {
                //Deve ser maior que os filhos
                //Obtem o maior filho
                //Se o filho for maior que ele, faz a troca
                higestChildPos = getTheValidChildPositionWithHigestValue(index);

                if (higestChildPos == -1)
                    break;

                //Verifica se deve fazer a troca
                if (numbers[index] < numbers[higestChildPos])
                {
                    swap = numbers[index];
                    numbers[index] = numbers[higestChildPos];
                    numbers[higestChildPos] = swap;

                    //index = higestChildPos;
                    //não altera o alreadyComparedWithChilds
                }
                else
                    alreadyComparedWithChilds = 1;
            }//fim de nível de máximo
        } //fim de comparação com filhos
        else //comparação com netos (os 4)
        {
            int myLevel = getLevelFromPosition(index);
            if (myLevel % 2 == 1) //impar - nível de mínimo
            {
                //Deve ser menor que os netos
                //Obtem o menor neto
                //Se o neto for menor que ele, faz a troca
                smallerGrandsonPos = getTheValidGrandsonPositionWithSmallerValue(index);

                if (smallerGrandsonPos == -1)
                    break;

                //Verifica se deve fazer a troca
                if (numbers[index] > numbers[smallerGrandsonPos])
                {
                    swap = numbers[index];
                    numbers[index] = numbers[smallerGrandsonPos];
                    numbers[smallerGrandsonPos] = swap;

                    //index = smallerGrandsonPos;
                    //continua comparando com outros netos
                }
                else
                    break; //não precisa comparar mais
            } //fim de nível de mínimo
            else //par - nível de máximo
            {
                //Deve ser maior que os netos
                //Obtem o maior neto
                //Se esse neto for maior que ele, troca
                higestGrandSon = getTheValidGrandsonPositionWithHigestValue(index);
                if (higestGrandSon == -1)
                    break;

                //Verifica se deve fazer a troca
                if (numbers[index] < numbers[higestGrandSon])
                {
                    swap = numbers[index];
                    numbers[index] = numbers[higestGrandSon];
                    numbers[higestGrandSon] = swap;

                    //continua comparando com outros netos
                }
                else
                    break; //não precisa comparar mais
            }
        }
    }
}
