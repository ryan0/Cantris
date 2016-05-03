Spatial = {
    position = {0, 0}
}

Physical = {
    b2BodyDef = {
        position = {40.0, 55.0},
        type = "b2_staticBody"
    },

    b2FixtureDef = {
        friction = .3,
        restitution = 0.0,
        b2PolygonShape = {
            setAsBox = {100, 1.0}
        }
    }
}