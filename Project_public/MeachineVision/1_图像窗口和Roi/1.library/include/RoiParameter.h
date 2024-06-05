#ifndef ROI_PARAMETER_H
#define ROI_PARAMETER_H

#include <QPointF>

namespace MVRoi
{
	/*
	* @brief ֱ�߲���
	*/
	struct MVLine
	{
		MVLine() :X1(0), Y1(0), X2(0), Y2(0) {}
		MVLine(float x1, float y1, float x2, float y2)
		{
			X1 = x1;
			Y1 = y1;
			X2 = x2;
			Y2 = y2;
		}
		MVLine(QPointF p1, QPointF p2)
		{
			X1 = p1.x();
			Y1 = p1.y();
			X2 = p2.x();
			Y2 = p2.y();
		}
		// �����߶��������
		float X1;
		float Y1;
		// �����߶��յ�����
		float X2;
		float Y2;
	};
	/*
	* @brief ����1ROI��������ƽ��������ϵ�ľ���
	*/
	struct MVRect
	{
		MVRect() :X(0), Y(0), Width(0), Height(0)
		{

		}
		MVRect(float x, float y, float width, float height)
		{
			X = x;
			Y = y;
			Width = width;
			Height = height;
		}
		MVRect(QPointF topLeft, float width, float height)
		{
			X = topLeft.x();
			Y = topLeft.y();
			Width = width;
			Height = height;
		}
		float X; //���Ͻ�X
		float Y; //���Ͻ�Y
		float Width;//���
		float Height;//�߶�
	};
	/*
	* @brief ����2ROI������������ת����б����
	*/
	struct MVRotateRect
	{
		MVRotateRect() :X(0), Y(0), Width(0), Height(0), Angle(0) {}
		MVRotateRect(float x, float y, float width, float height, float angle)
		{
			X = x;
			Y = y;
			Width = width;
			Height = height;
			Angle = angle;
		}
		MVRotateRect(QPointF center, float width, float height, float angle)
		{
			X = center.x();
			Y = center.y();
			Width = width;
			Height = height;
			Angle = angle;
		}
		float X; //���ĵ�X
		float Y; //���ĵ�Y
		float Width;//��
		float Height;//��
		float Angle;//��ת�Ƕ�,������x��ļн�
	};
	/*
	* @brief ԲROI����
	*/
	struct MVCircle
	{
		MVCircle() :X(0), Y(0), Radius(0)
		{

		}
		MVCircle(float x, float y, float radius)
		{
			X = x;
			Y = y;
			Radius = radius;
		}
		MVCircle(QPointF center, float radius)
		{
			X = center.x();
			Y = center.y();
			Radius = radius;
		}
		float X;
		float Y;
		float Radius;
	};
	/*
	* @brief ͬ��Բ
	*/
	struct MVConcentricCircle
	{
		MVConcentricCircle() :X(0), Y(0), Radius1(0), Radius2(0) {}
		MVConcentricCircle(float x, float y, float radius1, float radius2)
		{
			X = x;
			Y = y;
			Radius1 = radius1;
			Radius2 = radius2;
		}
		MVConcentricCircle(QPointF center, float radius1, float radius2)
		{
			X = center.x();
			Y = center.y();
			Radius1 = radius1;
			Radius2 = radius2;
		}
		float X;
		float Y;
		float Radius1;
		float Radius2;
	};

	/*
	* @brief ��ԲROI����
	*/
	struct Ellipse
	{
		float CenterX;
		float CenterY;
		float Phi;
		float Radius1;
		float Radius2;
	};
	/*
	* @brief ��ͼ
	*/
	struct MVPie
	{
		MVPie() {}
		float X;
		float Y;
		float Radius;
		float StartAngle;
		float EndAngle;
	};

	/*
	* @brief ��������·���㼯������(�����)
	*/
	struct MVPolygon
	{
		MVPolygon() {}
		MVPolygon(QVector<QPointF> pList)
		{
			PList = pList;
		}
		QVector<QPointF> PList;
	};

	/*
	* @brief ֱ�߿���
	*/
	struct MVStraightCaliper
	{
		MVStraightCaliper() :X1(0), Y1(0), X2(0), Y2(0), Width(0)
		{}
		MVStraightCaliper(float x1, float y1, float x2, float y2, float width)
		{
			X1 = x1;
			X2 = x2;
			Y1 = y1;
			Y2 = y2;
			Width = width;
		}
		MVStraightCaliper(QPointF p1, QPointF p2, float width)
		{
			X1 = p1.x();
			X2 = p2.x();
			Y1 = p1.y();
			Y2 = p2.y();
			Width = width;
		}
		float X1;
		float Y1;
		float X2;
		float Y2;
		float Width;
	};
	/*
	*@brief Բ�ο���
	*/
	struct MVCircularCaliper
	{
		MVCircularCaliper() :X(0), Y(0), Radius(0), MeasureRectWidth(0)
		{}
		MVCircularCaliper(float centerX, float centerY, float radius, float measureRectWidth)
		{
			X = centerX;
			Y = centerY;
			Radius = radius;
			MeasureRectWidth = measureRectWidth;
		}
		MVCircularCaliper(QPointF center, float radius, float measureRectWidth)
		{
			X = center.x();
			Y = center.y();
			Radius = radius;
			MeasureRectWidth = measureRectWidth;
		}
		float X;
		float Y;
		float Radius;
		float MeasureRectWidth;  //ͶӰ���εĳ��߳���
	};

	//Roi����ö��
	enum class RoiType
	{
		LINE = 1,			//ֱ��
		RECT,				//ƽ�о���
		ROTATE_RECT,		//�������
		CIRCLE,				//Բ
		CONCENTRIC_CIRCLE,	//ͬ��Բ
		//ELLIPSE,			//��Բ
		//PIE,				//��ͼ
		//POLYGON,			//��������
		STRAIGHT_CALLIPER,	//ֱ�߿���
		CIRCULAR_CALLIPER	//Բ����
	};
}

#endif // !

