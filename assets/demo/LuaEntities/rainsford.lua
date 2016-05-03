Renderable = {
    zValue = 0,
    position = {-0.8, -1.2}
}

Animated = {
    animation = "demo/stand.ani",
}

Spatial = {
    position = {0, 0},
    origin = {1, 1}
}

Movable = {
    velocity = {0, 0}
}

Physical = {
    b2BodyDef = {
        position = {0, 38},
        type = "b2_dynamicBody"
    },

    b2FixtureDef = {
        density = 1.0,
        friction = .3,
        restitution = .1,
        b2PolygonShape = {
            setAsBox = {0.8, 1.8}
        }
    }
}

PlayerControlled = {

}