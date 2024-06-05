#ifndef ROI_PARAMETER_H
#define ROI_PARAMETER_H

#include <QPointF>

namespace MVRoi
{
	/*
	* @brief 直线参数
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
		// 定义线段起点坐标
		float X1;
		float Y1;
		// 定义线段终点坐标
		float X2;
		float Y2;
	};
	/*
	* @brief 矩形1ROI参数，即平行与坐标系的矩形
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
		float X; //左上角X
		float Y; //左上角Y
		float Width;//宽度
		float Height;//高度
	};
	/*
	* @brief 矩形2ROI参数，即能旋转的倾斜矩形
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
		float X; //中心点X
		float Y; //中心点Y
		float Width;//长
		float Height;//宽
		float Angle;//旋转角度,长轴与x轴的夹角
	};
	/*
	* @brief 圆ROI参数
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
	* @brief 同心圆
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
	* @brief 椭圆ROI参数
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
	* @brief 饼图
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
	* @brief 任意区域路径点集合类型(多边形)
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
	* @brief 直线卡尺
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
	*@brief 圆形卡尺
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
		float MeasureRectWidth;  //投影矩形的长边长度
	};

	//Roi类型枚举
	enum class RoiType
	{
		LINE = 1,			//直线
		RECT,				//平行矩形
		ROTATE_RECT,		//方向矩形
		CIRCLE,				//圆
		CONCENTRIC_CIRCLE,	//同心圆
		//ELLIPSE,			//椭圆
		//PIE,				//饼图
		//POLYGON,			//任意区域
		STRAIGHT_CALLIPER,	//直线卡尺
		CIRCULAR_CALLIPER	//圆卡尺
	};
}

#endif // !

