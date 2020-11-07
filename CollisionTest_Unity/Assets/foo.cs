using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class foo : MonoBehaviour
{
    //!円
    [SerializeField] private ShapeCircle circleA = default;  
    [SerializeField] private ShapeCircle circleB = default;  

    //!矩形
    [SerializeField] private ShapeRect rectA = default;
    [SerializeField] private ShapeRect rectB = default;

    //!線分
    [SerializeField] private ShapeLine lineA = default;
    [SerializeField] private ShapeLine lineB = default;

    //!カプセル
    [SerializeField] private ShapeCapsule capsuleA = default;
    [SerializeField] private ShapeCapsule capsuleB = default;

    private void OnDrawGizmos()
    {
        //!円と円
        Gizmos.color = circleA.HitCircleToCircle(circleB) ? Color.red : Color.white;
        Gizmos.DrawLine(circleA.transform.position, circleB.transform.position);

        //!矩形と矩形
        Gizmos.color = rectA.HitRectToRect(rectB) ? Color.red : Color.white;
        Gizmos.DrawLine(rectA.transform.position, rectB.transform.position);

        //!線分と線分
        Gizmos.color = lineA.HitLineToLine(lineB) ? Color.red : Color.white;
        Gizmos.DrawLine(lineA.GetCenterPos(), lineB.GetCenterPos());

        //!カプセルとカプセル
        Gizmos.color = capsuleA.HitCapsuleToCapsule(capsuleB) ? Color.red : Color.white;
        Gizmos.DrawLine(capsuleA.GetCenterPos(), capsuleB.GetCenterPos());

        //!円と矩形
        Gizmos.color = rectA.HitRectToCircle(circleA) ? Color.red : Color.white;
        Gizmos.DrawLine(rectA.transform.position, circleA.transform.position);

        //!円と線分
        Gizmos.color = circleA.HitCircleToLine(lineA) ? Color.red : Color.white;
        Gizmos.DrawLine(circleA.transform.position, lineA.GetCenterPos());

        //!カプセルと円
        Gizmos.color = capsuleA.HitCapsuleToCircle(circleA) ? Color.red : Color.white;
        Gizmos.DrawLine(capsuleA.GetCenterPos(), circleA.transform.position);
    }
}
