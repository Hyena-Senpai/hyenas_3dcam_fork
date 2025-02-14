#include <physics.h>

short checkLineW( VECTOR * pointA, VECTOR * pointB, MESH * mesh ) {
    long val1 = ( ( mesh->body->position.vx + mesh->body->min.vx ) - pointA->vx ) * ( pointB->vy - pointA->vy ) - ( ( mesh->body->position.vz  + mesh->body->min.vy ) - pointA->vy ) * ( pointB->vx - pointA->vx ) ;
    long val2 = ( ( mesh->body->position.vx + mesh->body->max.vx ) - pointA->vx ) * ( pointB->vy - pointA->vy ) - ( ( mesh->body->position.vz  + mesh->body->max.vy ) - pointA->vy ) * ( pointB->vx - pointA->vx ) ;
    if ( val1 > 0 && val2 > 0 ) {
        // right
        return 1;
    }
    else if ( val1 < 0 && val2 < 0  ) {
        // left
        return -1;
    }
    else if ( val1 == 0 && val2 == 0 ) {
        // identical 
        return 0;
    }
    else if ( 
            ( val1 > 0  && val2 == 0 ) || 
            ( val1 == 0 && val2 > 0 ) 
            ) {
        // right
        return 1;
    }
    else if ( 
            ( val1 < 0  && val2 == 0 ) ||
            ( val1 == 0 && val2 < 0 ) 
            ) {
        // left
        return -1;
    }
    else if ( 
            ( val1 < 0 && val2 > 0 ) ||
            ( val1 > 0 && val2 < 0 ) 
            ) {
        // intersect
        return 3;
    }
};
// Screen space variant
short checkLineS( VECTOR * pointA, VECTOR * pointB, MESH * mesh ) {
    // FIXME : mesh->body->min.vx is not in screen space
    int val1 = ( ( mesh->pos2D.vx + mesh->body->min.vx ) - pointA->vx ) * ( pointB->vy - pointA->vy ) - ( ( mesh->pos2D.vy  + mesh->body->min.vy ) - pointA->vy ) * ( pointB->vx - pointA->vx ) ;
    int val2 = ( ( mesh->pos2D.vx + mesh->body->max.vx ) - pointA->vx ) * ( pointB->vy - pointA->vy ) - ( ( mesh->pos2D.vy  + mesh->body->max.vy ) - pointA->vy ) * ( pointB->vx - pointA->vx ) ;
    if ( val1 > 0 && val2 > 0 ) {
        // right
        return 1;
    }
    else if ( val1 < 0 && val2 < 0 ) {
        // left
        return -1;
    }
    else if ( val1 == 0 && val2 == 0 ) {
        // identical
        return 2;
    }
    else if ( 
            ( val1 > 0  && val2 == 0 ) || 
            ( val1 == 0 && val2 > 0 ) 
            ) {
        // right
        return 1;
    }
    else if ( 
            ( val1 < 0  && val2 == 0 ) ||
            ( val1 == 0 && val2 < 0 ) 
            ) {
        // left
        return -1;
    }
    else if ( 
            ( val1 < 0 && val2 > 0 ) ||
            ( val1 > 0 && val2 < 0 ) 
            ) {
        // intersect
        return 3;
    }
};
// Physics
VECTOR getIntCollision(BODY one, BODY two){
    VECTOR d1, d2, col;
    short correction = 50;
    d1.vx = (one.position.vx + one.max.vx) - (two.position.vx + two.min.vx);
    d1.vy = (one.position.vy + one.max.vy) - (two.position.vy + two.min.vy);
    d1.vz = (one.position.vz + one.max.vz) - (two.position.vz + two.min.vz);
    d2.vx = (two.position.vx + two.max.vx) - (one.position.vx - one.max.vx);
    d2.vy = (two.position.vy + two.max.vy) - (one.position.vy + one.min.vy);
    d2.vz = (two.position.vz + two.max.vz) - (one.position.vz - one.max.vz);
    col.vx = !(d1.vx > 0 && d2.vx > 0);
    col.vy = !(d1.vy > 0 && d2.vy > 0);
    col.vz = !(d1.vz > 0 && d2.vz > 0);
    return col;
};
VECTOR getExtCollision(BODY one, BODY two){
    VECTOR d1, d2, col;
    d1.vx = (one.position.vx + one.max.vx) - (two.position.vx + two.min.vx);
    d1.vy = (one.position.vy + one.max.vy) - (two.position.vy + two.min.vy);
    d1.vz = (one.position.vz + one.max.vz) - (two.position.vz + two.min.vz);
    d2.vx = (two.position.vx + two.max.vx) - (one.position.vx + one.min.vx);
    d2.vy = (two.position.vy + two.max.vy) - (one.position.vy + one.min.vy);
    d2.vz = (two.position.vz + two.max.vz) - (one.position.vz + one.min.vz);
    col.vx = d1.vx > 0 && d2.vx > 0;
    col.vy = d1.vy > 0 && d2.vy > 0;
    col.vz = d1.vz > 0 && d2.vz > 0;
    return col;
};
VECTOR checkBodyCol(BODY * one, BODY * two){
    VECTOR colInt;
    colInt = getIntCollision( *one , *two );
    // If collisiton on Y axis, 
    if ( !(colInt.vy) ) {
        // and above plane
        if ( !colInt.vx && !colInt.vz ) {
            // collide
            short slopeX = two->normal.vx > 0 ? 1 : -1;
            //~ short slopeZ = two->normal.vz > 0 ? 1 : -1;
            long o = two->max.vy - two->min.vy ;
            long a = two->max.vx - two->min.vx;
            long aa = (two->position.vx + two->min.vx) - (one->position.vx + one->min.vx) ;
            //~ long b = two->max.vz - two->min.vz;
            //~ long ab = (two->position.vz + two->min.vz) - (one->position.vz + one->min.vz) ;
            // Avoid div/0
            if (a){
                long y = (( (slopeX * o) * ONE) / a) * aa;
                // long y = (( (slopeZ * o) * ONE) / b) * ab;
                // FntPrint("sly: %d", y >> 12);
                if (y) {
                    one->position.vy = (y >> 12) - ( slopeX < 0 ? 128 : 0 );
                    // one->position.vy = (y >> 12) - ( slopeZ < 0 ? 64 : 0 )  ;
                } else {
                    one->position.vy = two->max.vy - one->max.vy;
                }
            }
            one->velocity.vy = 0;
            two->velocity.vy = 0;
            //~ FntPrint("col: %d %d %d %d\nY: %d, Z: %d, X: %d\nSlope: %d", o, a, aa, ab, one->position.vy, one->position.vz, one->position.vx, slopeX);
        }
    }
    return colInt;
};
void applyAngMom(LEVEL curLvl ){
    if (curLvl.propPtr->isRound){
        if ( curLvl.propPtr->body->velocity.vx ) {
            VECTOR L = angularMom( *curLvl.propPtr->body );
            curLvl.propPtr->rot.vz -= L.vx;
        }
        if ( curLvl.propPtr->body->velocity.vz ) {
            VECTOR L = angularMom( *curLvl.propPtr->body );
            curLvl.propPtr->rot.vx -= L.vz;
        }
    }
};
//~ void applyAcceleration(BODY * actor, int dt){
    //~ dt = 1;
    //~ VECTOR acceleration = {actor->invMass * actor->gForce.vx ,  (actor->invMass * actor->gForce.vy) + (GRAVITY * ONE), actor->invMass * actor->gForce.vz};
    //FntPrint("acc: %d %d %d\n", acceleration.vx, acceleration.vy, acceleration.vz );
    //~ actor->velocity.vx += (acceleration.vx * dt) >> 12;
    //~ actor->velocity.vy += (acceleration.vy * dt) >> 12;
    //~ actor->velocity.vz += (acceleration.vz * dt) >> 12;
    //FntPrint("acc: %d %d %d\n", acceleration.vx / ONE, acceleration.vy / ONE, acceleration.vz / ONE );
    //~ actor->position.vx += (actor->velocity.vx * dt);
    //~ actor->position.vy += (actor->velocity.vy * dt);
    //~ actor->position.vz += (actor->velocity.vz * dt);
    //FntPrint("vel: %d %d %d\n", actor->velocity.vx, actor->velocity.vy, actor->velocity.vz );
//~ };

void applyAcceleration(BODY * actor, int dt){
    // Make sure no div by 0 occurs
    if (dt < 1) { dt = 1; }
    int dtfx = ONE/dt;
    if (dtfx < 1) { dtfx = 1; }
    VECTOR acceleration = {actor->invMass * actor->gForce.vx , (actor->invMass * actor->gForce.vy) + (GRAVITY * ONE), actor->invMass * actor->gForce.vz};
    //~ FntPrint("acc: %d %d %d %d\n", acceleration.vx, acceleration.vy, acceleration.vz , delta);
    //~ actor->velocity.vx += (acceleration.vx * dt) >> 12;
    //~ actor->velocity.vy += (acceleration.vy * dt) >> 12;
    //~ actor->velocity.vz += (acceleration.vz * dt) >> 12;
    actor->velocity.vx += (acceleration.vx / dtfx) / 256;
    actor->velocity.vy += (acceleration.vy / dtfx) / 256;
    actor->velocity.vz += (acceleration.vz / dtfx) / 256;
    //~ FntPrint("acc: %d %d %d\n", (acceleration.vx / (ONE/dt)) , (acceleration.vy / (ONE/dt)), (acceleration.vz / (ONE/dt)) );
    //~ actor->position.vx += (actor->velocity.vx * dt);
    //~ actor->position.vy += (actor->velocity.vy * dt);
    //~ actor->position.vz += (actor->velocity.vz * dt);
    actor->position.vx += (actor->velocity.vx );
    actor->position.vy += (actor->velocity.vy );
    actor->position.vz += (actor->velocity.vz );
    //~ FntPrint("vel: %d %d %d\n", actor->velocity.vx, actor->velocity.vy, actor->velocity.vz );
};
//~ // https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331
void ResolveCollision( BODY * one, BODY * two ){
    //~ FntPrint("rv: %d, %d, %d\n", one->velocity.vx, one->velocity.vy, one->velocity.vz);
    // Calculate relative velocity
    VECTOR rv = { subVector( one->velocity, two->velocity) };
    //~ FntPrint("rv: %d, %d, %d\n", rv.vx,rv.vy,rv.vz);
    // Collision normal
    VECTOR normal = { subVector( two->position, one->position ) };
    // Normalize collision normal
    normal.vx = normal.vx > 0 ? 1 : normal.vx < 0 ? -1 : 0 ;
    normal.vy = normal.vy > 256 ? 1 : normal.vy < -256 ? -1 : 0 ;
    normal.vz = normal.vz > 0 ? 1 : normal.vz < 0 ? -1 : 0 ;
    //~ FntPrint("norm: %d, %d, %d\n", normal.vx,normal.vy,normal.vz);
    // Calculate relative velocity in terms of the normal direction
    long velAlongNormal = dotProduct( rv, normal );
    //~ FntPrint("velN: %d\n", velAlongNormal);
    // Do not resolve if velocities are separating
    if(velAlongNormal > 0)
    return;
    // Calculate restitution
    long e = min( one->restitution, two->restitution );
    //~ FntPrint("e: %d\n", e);
    //~ // Calculate impulse scalar
    long j = -(1 + e) * velAlongNormal * ONE;
    j /= one->invMass + two->invMass;
    //~ j /= ONE;
    //~ FntPrint("j: %d\n", j);
    // Apply impulse
    applyVector(&normal, j, j, j, *=);
    //~ FntPrint("Cnormal %d %d %d\n",normal.vx,normal.vy,normal.vz); 
    VECTOR velOne = normal;
    VECTOR velTwo = normal;
    applyVector(&velOne,one->invMass,one->invMass,one->invMass, *=);
    applyVector(&velTwo,two->invMass,two->invMass,two->invMass, *=);
    //~ FntPrint("V1 %d %d %d\n", velOne.vx/4096,velOne.vy/4096,velOne.vz/4096);
    //~ FntPrint("V2 %d %d %d\n", velTwo.vx/4096,velTwo.vy/4096,velTwo.vz/4096);
    applyVector(&one->velocity, velOne.vx/4096/4096, velOne.vy/4096/4096, velOne.vz/4096/4096, +=);
    applyVector(&two->velocity, velTwo.vx/4096/4096, velTwo.vy/4096/4096, velTwo.vz/4096/4096, -=);
    //~ FntPrint("V1 %d %d %d\n", velOne.vx/4096/4096,velOne.vy/4096/4096,velOne.vz/4096/4096);
    //~ FntPrint("V2 %d %d %d\n", velTwo.vx/4096/4096,velTwo.vy/4096/4096,velTwo.vz/4096/4096);
};
VECTOR angularMom(BODY body){
    // L = r * p
    // p = m * v  
    VECTOR w = {0,0,0,0};
    int r = (body.max.vx - body.min.vx) >> 1;
    w.vx = (r * body.mass * body.velocity.vx) >> 2; 
    w.vy = (r * body.mass * body.velocity.vy) >> 2; 
    w.vz = (r * body.mass * body.velocity.vz) >> 2; 
    //~ FntPrint("v: %d, r:%d, w:%d\n", body.velocity.vz * r, r * r, w.vz);
    return w;
};
u_int jump(BODY * actor, int dt){
    // https://medium.com/@brazmogu/physics-for-game-dev-a-platformer-physics-cheatsheet-f34b09064558
    // y = -0.5gt² + v't
    // vt = sqrt( (vel.vx)² + (vel.vz)² + (vel.vy - 9,81t)²  )
    //~ long long velocity = patan(actor->velocity.vx, actor->velocity.vy);
    //~ int y = (GRAVITY/2 * dt) + (velocity * dt );
    u_int vt = psqrt(  (actor->velocity.vx * actor->velocity.vx) + 
                       (actor->velocity.vz * actor->velocity.vz) + 
                       ( (actor->velocity.vy - (GRAVITY * dt)) * (actor->velocity.vy - (GRAVITY * dt)) )
                    );
    return vt;
};
void respawnMesh(LEVEL * level, MESH * mesh, VECTOR * rot, VECTOR * pos, NODE * node){
    // Actor
    if( mesh->isActor ){
        level->curNode = node;
        level->levelPtr = level->curNode->plane;
    } else {
        level->propPtr->node = node;
    }
    copyVector(&mesh->body->position, pos );
    copyVector(&mesh->rot, rot );
};
