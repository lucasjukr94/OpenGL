#include <string>

class GuiEntity{
    public:
        void SetDimension(double w, double h){
            width = w;
            height = h;
        }
    protected:
        virtual double width,height,x,y,fontSize;
        virtual string backgroundColor,borderColor,text,backgroundImage,fontFamily;
}

class Button : public GuiEntity{
    public:
        void GuiEntity
};
