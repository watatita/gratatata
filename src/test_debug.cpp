#include "test_debug.h"


position2di pos2convert(b2Vec2 box2dvector)
{
    position2di pos_tmp;
    pos_tmp.X=box2dvector.x;
    pos_tmp.Y=box2dvector.y;
    return pos_tmp;
}

//debug untuk menampilkan object dalam 2D
void debug_object(IVideoDriver* d_driver,b2World* d_world)
{
    b2Body* dbody=NULL;
    for(dbody=d_world->GetBodyList();dbody;dbody=dbody->GetNext())
        {
         if(dbody->GetFixtureList()!=NULL) //cek fixture dalam body
          {
            b2PolygonShape* a=(b2PolygonShape*) dbody->GetFixtureList()->GetShape(); //ambil fixture dalam body
            int maxvert=a->GetVertexCount(); //cari nilai maxvertex
            b2Vec2 vert_a[maxvert];
            for(int i=0;i<maxvert;i++)
            {
                vert_a[i]=dbody->GetWorldPoint(a->GetVertex(i)); //ambil nilai semua vertex
            }
            //gambar bentuk fixture
            for(int i=0;i<maxvert-1;i++)
            {
                d_driver->draw2DLine(pos2convert(vert_a[i]),pos2convert(vert_a[i+1]),SColor(0xff,0xff,0xf0,0xf0));
            }
            d_driver->draw2DLine(pos2convert(vert_a[0]),pos2convert(vert_a[maxvert-1]),SColor(0xff,0xff,0xf0,0xf0));
           }
        }
}

//debug untuk menampilkan object Box2D dalam 3D
void debug_object_3D(IVideoDriver* d_driver,b2World* d_world)
{
    b2Body* dbody=NULL;
    for(dbody=d_world->GetBodyList();dbody;dbody=dbody->GetNext())
        {
         if(dbody->GetFixtureList()!=NULL) //cek fixture dalam body
          {

            b2PolygonShape* a=(b2PolygonShape*) dbody->GetFixtureList()->GetShape(); //ambil fixture dalam body

            /*
            int maxvert=a->GetVertexCount(); //cari nilai maxvertex
            b2Vec2 vert_a[maxvert];
            core::vector3df t_vect[maxvert];
            for(int i=0;i<maxvert;i++)
            {
                vert_a[i]=dbody->GetWorldPoint(a->GetVertex(i)); //ambil nilai semua vertex
                t_vect[i].X=vert_a[i].x;
                t_vect[i].Y=vert_a[i].y;
                t_vect[i].Z=10;
            }
            //gambar bentuk fixture
            for(int i=0;i<maxvert-1;i++)
            {
                d_driver->draw3DLine(t_vect[i],t_vect[i+1],SColor(0xff,0xff,0xff,0xff));
            }
            d_driver->draw3DLine(t_vect[0],t_vect[maxvert-1],SColor(0xff,0xff,0xff,0xff));
            */
            irr::core::aabbox3df r;

            b2Vec2 vert_a[4];
            core::vector3df t_vect[4];
            for(int i=0;i<4;i++)
            {
                vert_a[i]=dbody->GetWorldPoint(a->GetVertex(i)); //ambil nilai semua vertex
                t_vect[i].X=vert_a[i].x;
                t_vect[i].Y=vert_a[i].y;
                t_vect[i].Z=0;
            }

//            d_driver->draw3DLine(t_vect[0],t_vect[1],SColor(0xff,0xff,0xff,0xff));
            d_driver->draw3DLine(t_vect[0],t_vect[3],SColor(0xff,0xff,0xff,0xff));
//            d_driver->draw3DLine(t_vect[3],t_vect[2],SColor(0xff,0xff,0xff,0xff));
//            d_driver->draw3DLine(t_vect[1],t_vect[3],SColor(0xff,0xff,0xff,0xff));

           }

        }
}
