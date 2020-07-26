#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>
#include <vector>

/*!
 * \brief The ColorRepresentation enum
 */
enum ColorRepresentation
{
    BLUE, //to min level
    RED //to max level
};

/*!
 * \brief The MinMaxHeap class
 */
class MinMaxHeap
{
public:
    /*!
     * \brief MinMaxHeap
     */
    MinMaxHeap();

    ~MinMaxHeap();

    /*!
     * \brief realToVirtual
     * \param realPosition
     * \return
     */
    int realToVirtual(int realPosition);

    /*!
     * \brief virtualToReal
     * \param virtualPosition
     * \return
     */
    int virtualToReal(int virtualPosition);

    /*!
     * \brief leftChildRealPos
     * \param realPosition
     * \return
     */
    int leftChildRealPos(int realPosition);

    /*!
     * \brief rightChildRealPos
     * \param realPosition
     * \return
     */
    int rightChildRealPos(int realPosition);

    /*!
     * \brief getFatherRealPosition
     * \param realPosition
     * \return
     */
    int getFatherRealPosition(int realPosition);

    /*!
     * \brief upsideCheckAndMove
     * \param realPos
     */
    void upsideCheckAndMove(int realPos);

    /*!
     * \brief insertInterface
     * \param number
     */
    void insertInterface(int number);

    /*!
     * \brief removeTheSmallerNumber
     * \return
     */
    int removeTheSmallerNumber();

    /*!
     * \brief removeTheHiguestNumber
     * \return
     */
    int removeTheHiguestNumber();

    /*!
     * \brief getLevelFromPosition
     * \param realPos
     * \return
     */
    int getLevelFromPosition(int realPos);

    /*!
     * \brief getColorIndex
     * \param realPosition
     * \return
     */
    ColorRepresentation getColorIndex(int realPosition);

    /*!
     * \brief gitDotFileMode1
     * \return
     */
    const std::string gitDotFileMode1();

    /*!
     * \brief gitDotFileMode12
     * \return
     */
    const std::string gitDotFileMode12();

    /*!
     * \brief getNumberOfElementsInTheVector
     * \return
     */
    int getNumberOfElementsInTheVector();

    /*!
     * \brief getHeapAsAVector
     * \return
     */
    std::vector<int> getHeapAsAVector();
private:
    //The zero position cannot be used
    std::vector<int> numbers;

    /*!
     * \brief insert
     * \param number
     * \return The position where the number was inserted
     */
    int insert(int number);

    /*!
     * \brief getTheValidChildPositionWithSmallerValue
     * \param fatherPosition
     * \return
     */
    int getTheValidChildPositionWithSmallerValue(int fatherPosition);

    /*!
     * \brief getTheValidChildPositionWithHigestValue
     * \param fatherPosition
     * \return
     */
    int getTheValidChildPositionWithHigestValue(int fatherPosition);

    /*!
     * \brief getTheValidGrandsonPositionWithSmallerValue
     * \param fatherPosition
     * \return
     */
    int getTheValidGrandsonPositionWithSmallerValue(int fatherPosition);

    /*!
     * \brief getTheValidGrandsonPositionWithHigestValue
     * \param fatherPosition
     * \return
     */
    int getTheValidGrandsonPositionWithHigestValue(int fatherPosition);

    /*!
     * \brief moveDownside
     * \param position
     */
    void moveDownside(int position);

};

#endif // MINMAXHEAP_H
