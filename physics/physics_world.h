#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H


#define dSINGLE
#include <ode/ode.h>

#include <engine/core/double3.h>
#include <engine/physics/physical.h>
#include <engine/physics/physicsgroup.h>

class PhysicsWorld{
private:

    /*physics world stuff for the fps*/
    static dWorldID worldID;
    static dSpaceID spaceID;
    static dJointGroupID contactGroup;
	static double stepSize;

    static void NearCallback (void *data, dGeomID o1, dGeomID o2);

    static void Init(){
        cout << "Initialize physics\n";
        stepSize  = .01;
        worldID = dWorldCreate();
        spaceID = dHashSpaceCreate(0);
        contactGroup = dJointGroupCreate(0);
    }

public:


    PhysicsWorld();
    ~PhysicsWorld();


    static void Step();


    static void PhysicsSettings(VarMap settings);


    /*set the world settings, like bounciness, constant force mixing, gravity, etc.*/
    static double3 SetGravity(const double3 newGravity);


    /*create new 3d shapes of coolness*/
    /**\brief Creates a new box in the current physics space and world.

    The box needs dimensions, so a length, width, and height. It also needs a density,
    and it should have a reference to the node that it is being created for added as
    the void* argument.*/
    static void NewBox(dBodyID &body,dGeomID &geom,double3 dimensions,double density,void* data);

    /**\brief Creates new plane in the current physics space and world.

    The normal of the normal is used to determine the angle of the plane, the
    offset is used to determine how far away from the origin the plane sits.

    Since this plane does not have a body,
    it will be static by default, meaning that it has no mass and cannot be
    moved by any objects. It is an immovable object.*/
    static void NewPlane(dGeomID &geom,double3 normal,double offset,void* data);

    /**\brief Create new sphere in the current physics space and world.

    It creates a sphere. It needs a radius. 'nuff said.*/
    static void NewSphere(dBodyID &body,dGeomID &geom,double radius,double density,void* data);

    static void NewCylinder(dBodyID &body,dGeomID &geom,double radius,double length,double density,void* data);

    static PhysicsGroup* BuildPhysicsGroup(VarMap* groupSettings,void* data);


    static void GlMatrix(dBodyID body,float *matrix);
    static void GlMatrix(dGeomID geom,float *matrix);


};
#endif // PHYSICS_WORLD_H



